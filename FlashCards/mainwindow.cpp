#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Card.h"
#include "addnewtermdialog.h"
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
    , add(new AddNewTermDialog(this))
{
    ui->setupUi(this);

    QString sessionFile("../FlashCards/Data/session.txt");
    if(QFileInfo::exists(sessionFile)) {
        int ret = QMessageBox::information(this, "A saved session has been detected",
                                           "Do you want to load the last saved session?",
                                           QMessageBox::No, QMessageBox::Yes);
        if (ret == QMessageBox::Yes) {
            loadSession();
            beginSet();
            on_pushButtonStart_clicked();
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
        int ret = QMessageBox::information(this, "",
                                           "Do you want to load the default database?",
                                           QMessageBox::No, QMessageBox::Yes);
        if (ret == QMessageBox::Yes) {
            filePath = "../FlashCards/Data/PLtoENG.txt";
            readFile(cardList, filePath);
        }
        else {
            on_actionOpenDatabase_triggered();
        }
    }
    beginSet();

    connect(add, &AddNewTermDialog::createdNewTerm, this, &MainWindow::addCard);
}

void MainWindow::showStatusBar()
{
    ui->statusbar->showMessage("Total flashcards: " + QString::number(cardList.size()));
}

Card MainWindow::returnCurrentItem() const
{
  return cardList[index];
}

int MainWindow::getIndex() const
{
    return index;
}

int MainWindow::getPoints() const {
    return points;
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
    delete add;
    delete ui;
}

void MainWindow::on_actionOpenDatabase_triggered()
{
    checkEditStatus();
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Choose flashcard database"), "../FlashCards/Data", tr("Text files (*.txt)"));
    if(fileName != "") {
        filePath = fileName;
        readFile(cardList, fileName);
        ui->labelShowTerm->hide();
        ui->groupBoxInput->hide();
        ui->groupBoxSummary->hide();
        ui->pushButtonStart->setDisabled(false);
        ui->pushButtonStartOver->setDisabled(true);
    }
    beginSet();
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
    if(checkGrade(answer)) {
        ui->labelUserAnswer->setStyleSheet("QLabel {color: green;}");
        ++points;
    }
    else {
        ui->labelUserAnswer->setStyleSheet("QLabel {color: red;}");
    }
    ui->labelUserAnswer->setText(answer);
    ui->labelCorrectMessage->setText(correctAnswer);
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
    QWidget::close();
}

void MainWindow::on_actionAddNewDatabase_triggered()
{
    checkEditStatus();
    QString path = QInputDialog::getText(this, "Create new data base", "Input flashcards database name");
    if (path != "") {
        path = "../FlashCards/Data/" + path + ".txt";
        QFile file{path};

        if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
            QTextStream out(&file);
            out << "";
            file.close();
        }
        filePath = path;
        readFile(cardList, filePath);
        editStatus = true;
        on_actionAdd_new_terms_triggered();
        beginSet();
    }

}

void MainWindow::on_toolBarAddNewDatabase_triggered()
{
    on_actionAddNewDatabase_triggered();
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
    if(!cardList.empty()) {
        if(!cardList.empty()) {
            auto index = cardList.begin() + getIndex();
            cardList.erase(index);
            editStatus = true;
        }
        on_pushButtonStart_clicked();
        on_pushButtonNext_clicked();
        editStatus = true;
    }
}

void MainWindow::on_toolBarDeleteTerm_triggered()
{
    on_actionDeleteTerm_triggered();
}

void MainWindow::loadSession() {
    checkEditStatus();
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
    beginSet();

}

bool MainWindow::checkGrade(QString& answ) const
{
    std::string answer = answ.toStdString();
    removeWhiteSpace(answer);
    Card current = returnCurrentItem();
    std::string correct = current.getDef();
    removeWhiteSpace(correct);
    if(answer == correct) return true;
    return false;
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

void MainWindow::addCard(Card& card){
    cardList.push_back(card);
    editStatus = true;
    this->showStatusBar();
};

void MainWindow::on_actionAdd_new_terms_triggered()
{   
    add->setModal(true);
    add->exec();
    ui->pushButtonStart->setDisabled(false);
}

void MainWindow::on_toolBarAddNewTerms_triggered()
{
    on_actionAdd_new_terms_triggered();
}

bool MainWindow::checkEditStatus() {
    // 1 - quit
    // 0 - do not quit
    if(editStatus == true) {
        int ret = QMessageBox::warning(this, "Warning!",
                                           "You've edited the current set. Do you want to save it?",
                                           QMessageBox::No, QMessageBox::Yes, QMessageBox::Cancel);
        if (ret == QMessageBox::Yes) {
            on_actionSaveDatabase_triggered();
            return 1;
        }
        else if (ret == QMessageBox::No) {
            return 1;
        }
        else if (ret == QMessageBox::Cancel) {
            return 0;
        }
    }
    return 1;
}

void MainWindow::beginSet() {
    points = 0;
    ui->labelShowTerm->setText("");
    ui->groupBoxSummary->hide();
    ui->pushButtonStartOver->setDisabled(true);
    if(cardList.size() == 0) {
        ui->pushButtonStart->setDisabled(true);
    }
    ui->pushButtonNext->hide();
    ui->groupBoxInput->hide();
}

void MainWindow::closeEvent(QCloseEvent *event) {
    if (checkEditStatus()) {
        event->accept();
    }
    else {
        event->ignore();
    }
}



