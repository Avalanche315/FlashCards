#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Card.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include <QInputDialog>

void removeWhiteSpace(std::string& w);
void showStatusBar();

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString sessionFile("../FlashCards/Data/session.txt");
    if(QFileInfo::exists(sessionFile)) {
        int ret = QMessageBox::information(this, "A saved session has been detected", "Do you want to load the last saved session?", QMessageBox::No, QMessageBox::Yes);
        if (ret == QMessageBox::Yes) {
            loadSession();
        }
        else {
            // removing session file
            QFile sFile(sessionFile);
            sFile.remove();
            // establish default database
            filePath = "../FlashCards/Data/PLtoENG.txt";
            readFile(cardList, filePath);
        }
    }
    else {
        filePath = "../FlashCards/Data/PLtoENG.txt";
        readFile(cardList, filePath);
    }
    ui->labelShowTerm->setText("");
    ui->groupBoxSummary->hide();
    ui->pushButtonStartOver->setDisabled(true);
    ui->pushButtonNext->hide();
    ui->pushButtonAddNewTerm->setDisabled(true);
    ui->groupBoxInput->hide();
}

void MainWindow::showStatusBar()
{
    ui->statusbar->showMessage("Total flashcards: " + QString::number(cardList.size()));
}

Card MainWindow::returnCurrentItem()
{
  return cardList[index];
}

int MainWindow::getIndex()
{
    return index;
}

void MainWindow::readFile(std::vector<Card>& list, QString filePath) {
    list.clear();

    index = 0;

    QFile file{filePath};

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error with loading the file: " << file.errorString();
        return;
    }

    while (!file.atEnd()) {
        std::string term = file.readLine().toStdString();
        removeWhiteSpace(term);
        std::string def = file.readLine().toStdString();
        removeWhiteSpace(def);
        long long int points = 0;
        list.push_back(Card(term, def, points));
    }

    file.close();

    this->showStatusBar();
    if(cardList.size() == 0) {
        ui->pushButtonStart->setDisabled(true);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpenDatabase_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Browse file"), "../FlashCards/Data", tr("Text files (*.txt)"));
    if(fileName != "") {
        filePath = fileName;
        readFile(cardList, fileName);
        ui->labelShowTerm->hide();
        ui->groupBoxInput->hide();
        ui->groupBoxSummary->hide();
        ui->pushButtonStart->setDisabled(false);
        ui->pushButtonStartOver->setDisabled(true);
    }
}

void MainWindow::on_pushButtonAddNewTerm_clicked()
{
    std::string term{};
    term = ui->lineEditInputTerm->text().toStdString();
    std::string def{};
    def = ui->lineEditInputDefinition->text().toStdString();
    cardList.push_back(Card(term, def, 0));
    this->showStatusBar();
    ui->lineEditInputTerm->clear();
    ui->lineEditInputDefinition->clear();
    if(cardList.size() != 0) {
        ui->pushButtonStart->setDisabled(false);
    }
    ui->pushButtonAddNewTerm->setDisabled(true);
}

void MainWindow::on_toolBarOpenDatabase_triggered()
{
    on_actionOpenDatabase_triggered();
}

void MainWindow::on_pushButtonShowAnswer_clicked()
{
    if(index < int(cardList.size()-1)) {
       ui->pushButtonNext->setDisabled(false);
    }
    else {
        ui->pushButtonNext->setDisabled(true);
        ui->pushButtonStartOver->setDisabled(false);
    }
    showSummary();
    ui->pushButtonShowAnswer->setDisabled(true);
    ui->lineEditInputAnswer->setDisabled(true);
}

void MainWindow::showSummary()
{
    Card currentCard = returnCurrentItem();
    QString answer = QString(ui->lineEditInputAnswer->text());
    QString correctAnswer = QString(QString::fromStdString(currentCard.getDef()));
    ui->groupBoxSummary->show();
    ui->pushButtonNext->show();
    ui->labelUserAnswer->setText(answer);
    ui->labelCorrectMessage->setText(correctAnswer);
    ui->labelUsersGrade->setText(QString::number(checkGrade(answer)));
}

void MainWindow::on_lineEditInputTerm_textEdited()
{
    if(ui->lineEditInputTerm->text() != "" && ui->lineEditInputDefinition->text().toStdString() != "") {
        ui->pushButtonAddNewTerm->setDisabled(false);
    }
    else {
        ui->pushButtonAddNewTerm->setDisabled(true);
    }
}

void MainWindow::on_lineEditInputDefinition_textEdited()
{
    if(ui->lineEditInputTerm->text() != "" && ui->lineEditInputDefinition->text().toStdString() != "") {
        ui->pushButtonAddNewTerm->setDisabled(false);
    }
    else {
        ui->pushButtonAddNewTerm->setDisabled(true);
    }
}

void removeWhiteSpace(std::string& w) {
    if(w.size() != 0) {
        w.replace(w.end() - 1, w.end(), "");
    }
}

void MainWindow::on_pushButtonStart_clicked()
{
    QString term{};
    term = QString::fromStdString(returnCurrentItem().getTerm());
    ui->labelShowTerm->setText(term);
    ui->pushButtonStart->setDisabled(true);
    ui->lineEditInputAnswer->clear();
    ui->lineEditInputAnswer->setDisabled(false);
    ui->pushButtonNext->setDisabled(false);
    ui->pushButtonShowAnswer->setDisabled(false);
    ui->labelShowTerm->show();
    ui->groupBoxInput->show();
    ui->pushButtonStartOver->setDisabled(false);
    this->showStatusBar();
}

void MainWindow::on_pushButtonNext_clicked()
{
    ui->lineEditInputAnswer->clear();
    ui->groupBoxSummary->hide();
    ui->lineEditInputAnswer->setDisabled(false);
    ui->pushButtonShowAnswer->setDisabled(false);
    ui->pushButtonNext->hide();
    this->index++;
    on_pushButtonStart_clicked();
}

void MainWindow::on_lineEditInputAnswer_returnPressed()
{
    if(ui->lineEditInputAnswer->text() != "") {
        on_pushButtonShowAnswer_clicked();
    }
}

void MainWindow::on_pushButtonStartOver_clicked()
{
    ui->pushButtonStartOver->setDisabled(true);
    index = 0;
    on_pushButtonStart_clicked();
    ui->groupBoxSummary->hide();
    ui->lineEditInputAnswer->clear();
    ui->lineEditInputAnswer->setDisabled(false);
    ui->pushButtonShowAnswer->setDisabled(false);
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_actionAddNewDatabase_triggered()
{
    QString path = QInputDialog::getText(this, "Create new data base", "Input flashcards database name");
    path = "../FlashCards/Data/" + path + ".txt";
    QFile file{path};

    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream out(&file);
        out << "";
        file.close();
    }
    filePath = path;
    readFile(cardList, filePath);
}

void MainWindow::on_actionSaveDatabase_triggered()
{
    QFile file{filePath};
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream out(&file);
        for(auto& it : cardList) {
            QString term = QString::fromStdString(it.getTerm());
            QString def = QString::fromStdString(it.getDef());
            out << term << "\n" << def << "\n";
        }
        file.close();
    }
}

void MainWindow::on_toolBarSaveDatabase_triggered()
{
    on_actionSaveDatabase_triggered();
}

void MainWindow::on_actionDeleteTerm_triggered()
{
    auto index = cardList.begin() + getIndex();
    cardList.erase(index);
    index += 1;
    on_pushButtonStart_clicked();
}

void MainWindow::on_toolBarDeleteTerm_triggered()
{
    on_actionDeleteTerm_triggered();
}

void MainWindow::loadSession() {
    QFile file{"../FlashCards/Data/session.txt"};

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error with loading the file: " << file.errorString();
        return;
    }
    else {
        std::string fileName = file.readLine().toStdString();
        removeWhiteSpace(fileName);
        filePath = QString::fromStdString(fileName);
        QString name = QString::fromStdString(fileName);
        readFile(cardList, name);
        index = file.readLine().toInt();
    }
    file.close();
}

int MainWindow::checkGrade(QString answ)
{
    int grade = 6;
    Card item = returnCurrentItem();
    char def[item.getDef().size()+1];
    strcpy(def, item.getDef().c_str());
    char answer[answ.size()+1];
    strcpy(answer, answ.toStdString().c_str());

    int counter = 0;

    if(strlen(answer) > 0) {
        if(strlen(def) >= strlen(answer)) {
            for(int i = 0; i <= int(strlen(answer)); i++) {
                if (def[i] != answer[i]) {
                    grade--;
                }
                else
                    counter++;
            }
        }
        else {
            for(int i = 0; i <= int(strlen(def)); i++) {
                if (def[i] != answer[i]) {
                    grade--;
                }
                else
                    counter++;
            }
        }
    }
    else {
        return 1;
    }


    if(grade <= 0)
        grade = 1;

    if(counter == 0)
        return 1;

    return grade;

};

void MainWindow::on_actionSaveSession_triggered()
{
    QFile file{"../FlashCards/Data/session.txt"};
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream out(&file);
        out << filePath << "\n" << index << "\n";
        file.close();
    }
}

void MainWindow::on_toolBarSaveSession_triggered()
{
   on_actionSaveSession_triggered();
}
