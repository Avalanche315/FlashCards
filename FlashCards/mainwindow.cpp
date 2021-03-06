#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Card.h"
#include "addnewtermdialog.h"
#include "additionalfunctions.h"
#include "sessionmanager.h"
#include "databasemanager.h"
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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , add(new AddNewTermDialog(this))
    , score(new SetSummaryDialog(this))
    , cardList(new CardManager())
{
    ui->setupUi(this);

    SessionManager sessionManager{this};
    sessionManager.establishBasicSet();

    connect(add, &AddNewTermDialog::createdNewTerm, this, &MainWindow::addCard);
    connect(this, &MainWindow::setEnded, score, &SetSummaryDialog::showScore);
}

void MainWindow::deactivateStartButton() {
    ui->pushButtonStart->setDisabled(true);
}

void MainWindow::beginSet(int index) {
    ui->labelShowTerm->setText("");
    ui->groupBoxSummary->hide();
    cardList->setIndex(index);

    ui->pushButtonRestart->setDisabled(true);
    if(cardList->size() == 0) {
        ui->pushButtonStart->setDisabled(true);
    }
    else {
        ui->pushButtonStart->setDisabled(false);
    }
    ui->pushButtonNext->hide();
    ui->groupBoxInput->hide();
}

void MainWindow::showStatusBar()
{
    ui->statusbar->showMessage("Total flashcards: " + QString::number(cardList->size()));
}

MainWindow::~MainWindow()
{
    delete add;
    delete ui;
    delete score;
    delete cardList;
}

void MainWindow::on_actionOpenDatabase_triggered()
{
    SessionManager sessionManager(this);
    sessionManager.checkEditStatus();
    DataBaseManager databaseManager(this);
    bool status = databaseManager.openDatabase();
    if(status) {
        beginSet();
    }
}

void MainWindow::on_toolBarOpenDatabase_triggered()
{
    on_actionOpenDatabase_triggered();
}

void MainWindow::on_pushButtonShowAnswer_clicked()
{
    if(cardList->getIndex() < static_cast<int>(cardList->size()-1)) {
       ui->pushButtonNext->setDisabled(false);
       showSummary();
    }
    else { // if set is ended
        emit setEnded(cardList->getPoints(), cardList->size());
        showSummary();
        ui->pushButtonNext->setDisabled(true);
        score->setModal(true);
        score->exec();
    }
    ui->pushButtonShowAnswer->setDisabled(true);
    ui->lineEditInputAnswer->setDisabled(true);

}

void MainWindow::showSummary()
{
    Card currentCard = cardList->returnCurrentItem();
    QString answer = QString(ui->lineEditInputAnswer->text());
    QString correctAnswer = QString(QString::fromStdString(currentCard.getDef()));
    ui->groupBoxSummary->show();
    ui->pushButtonNext->show();
    if(checkGrade(answer)) {
        ui->labelUserAnswer->setStyleSheet("QLabel {color: green;}");
        cardList->increasePoints();
    }
    else {
        ui->labelUserAnswer->setStyleSheet("QLabel {color: red;}");
    }
    ui->labelUserAnswer->setText(answer);
    ui->labelCorrectMessage->setText(correctAnswer);
}

void MainWindow::on_pushButtonStart_clicked()
{
    QString term{};
    term = QString::fromStdString(cardList->returnCurrentItem().getTerm());
    ui->labelShowTerm->setText(term);
    ui->pushButtonStart->setDisabled(true);
    ui->lineEditInputAnswer->clear();
    ui->lineEditInputAnswer->setDisabled(false);
    ui->pushButtonNext->setDisabled(false);
    ui->pushButtonShowAnswer->setDisabled(false);
    ui->labelShowTerm->show();
    ui->groupBoxInput->show();
    ui->pushButtonRestart->setDisabled(false);
    this->showStatusBar();
}

void MainWindow::on_pushButtonNext_clicked()
{
    ui->lineEditInputAnswer->clear();
    ui->groupBoxSummary->hide();
    ui->lineEditInputAnswer->setDisabled(false);
    ui->pushButtonShowAnswer->setDisabled(false);
    ui->pushButtonNext->hide();
    cardList->increaseIndex();
    on_pushButtonStart_clicked();
}

void MainWindow::on_lineEditInputAnswer_returnPressed()
{
    if(ui->lineEditInputAnswer->text() != "") {
        on_pushButtonShowAnswer_clicked();
    }
}

void MainWindow::on_pushButtonRestart_clicked()
{
    ui->pushButtonRestart->setDisabled(true);
    cardList->setIndex(0);
    cardList->setPoints(0);
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
    SessionManager sessionManager(this);
    sessionManager.checkEditStatus();
    DataBaseManager manager(this);
    bool status = manager.addNewDatabase();
    if(status) beginSet();
}

void MainWindow::on_toolBarAddNewDatabase_triggered()
{
    on_actionAddNewDatabase_triggered();
}

void MainWindow::on_actionSaveDatabase_triggered()
{
    DataBaseManager manager(this);
    manager.saveDatabase();
}

void MainWindow::on_toolBarSaveDatabase_triggered()
{
    on_actionSaveDatabase_triggered();
}

void MainWindow::on_actionDeleteTerm_triggered()
{
    editStatus = cardList->deleteCard();
    if(editStatus) {
        on_pushButtonStart_clicked();
        on_pushButtonNext_clicked();
    }
}

void MainWindow::on_toolBarDeleteTerm_triggered()
{
    on_actionDeleteTerm_triggered();
}

bool MainWindow::checkGrade(QString& answ) const
{
    std::string answer = answ.toStdString();
    AdditionalFunctions::removeWhiteSpace(answer);
    Card current = cardList->returnCurrentItem();
    std::string correct = current.getDef();
    AdditionalFunctions::removeWhiteSpace(correct);
    if(answer == correct) return true;
    return false;
};

void MainWindow::addCard(Card& card){
    cardList->push_back(card);
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

void MainWindow::closeEvent(QCloseEvent *event) {
    SessionManager sessionManager(this);
    if (sessionManager.checkEditStatus()) {
        SessionManager manager(this);
        manager.saveSession();
        event->accept();
    }
    else {
        event->ignore();
    }
}
