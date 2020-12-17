#pragma once

#include <QMainWindow>
#include <QCloseEvent>
#include "Card.h"
#include "addnewtermdialog.h"
#include "setsummarydialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    Card returnCurrentItem() const;
    void showStatusBar();
    void showSummary();
    bool checkGrade(QString& answer) const;
    int getIndex() const;
    int getPoints() const;
    ~MainWindow();
protected:
    virtual void closeEvent(QCloseEvent *event) override;

signals:
    void setEnded(int points, int totalPoints);

public slots:
    void deactivateStartButton();
    void beginSet();

private slots:
    void on_actionOpenDatabase_triggered();
    void on_toolBarOpenDatabase_triggered();
    void on_pushButtonShowAnswer_clicked();
    void on_pushButtonStart_clicked();
    void on_pushButtonNext_clicked();
    void on_lineEditInputAnswer_returnPressed();
    void on_pushButtonRestart_clicked();
    void on_actionExit_triggered();
    void on_actionAddNewDatabase_triggered();
    void on_actionSaveDatabase_triggered();
    void on_toolBarSaveDatabase_triggered();
    void on_actionDeleteTerm_triggered();
    void on_toolBarDeleteTerm_triggered();;
    void on_actionAdd_new_terms_triggered();
    void on_toolBarAddNewTerms_triggered();
    void on_toolBarAddNewDatabase_triggered();
    void addCard(Card& card);

private:
    Ui::MainWindow *ui;
    AddNewTermDialog* add;
    SetSummaryDialog* score;
    std::vector<Card> cardList{};
    QString filePath;
    bool editStatus{};
    int index;
    int points{};
    bool checkEditStatus();
    friend class SessionManager;
    friend class DataBaseManager;
};
