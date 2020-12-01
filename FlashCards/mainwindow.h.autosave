#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Card.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void showStatusBar();
    void showSummary();
    void loadSession();
    int checkGrade(QString answer);
    Card returnCurrentItem();
    int getIndex();
    ~MainWindow();

public slots:
    void readFile(std::list<Card>& list, QString fileName);

private slots:
    void on_actionOpenDatabase_triggered();

    void on_pushButtonAddNewTerm_clicked();

    void on_toolBarOpenDatabase_triggered();

    void on_pushButtonShowAnswer_clicked();

    void on_lineEditInputTerm_textEdited();

    void on_lineEditInputDefinition_textEdited();

    void on_pushButtonStart_clicked();

    void on_pushButtonNext_clicked();

    void on_lineEditInputAnswer_returnPressed();

    void on_pushButtonStartOver_clicked();

    void on_actionExit_triggered();

    void on_actionAddNewDatabase_triggered();

    void on_actionSaveDatabase_triggered();

    void on_toolBarSaveDatabase_triggered();

    void on_actionDeleteTerm_triggered();

    void on_toolBarDeleteTerm_triggered();

    void on_actionSaveSession_triggered();

    void on_toolBarSaveSession_triggered();

private:
    Ui::MainWindow *ui;
    std::list<Card> cardList{};
    QString filePath;
    int index;
};
#endif // MAINWINDOW_H
