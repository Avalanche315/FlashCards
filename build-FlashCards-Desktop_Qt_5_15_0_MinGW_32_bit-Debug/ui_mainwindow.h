/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionOpenDatabase;
    QAction *actionAddNewDatabase;
    QAction *actionDeleteTerm;
    QAction *toolBarDeleteTerm;
    QAction *toolBarAddNewDatabase;
    QAction *toolBarOpenDatabase;
    QAction *actionSaveDatabase;
    QAction *toolBarSaveDatabase;
    QAction *actionSaveSession;
    QAction *toolBarSaveSession;
    QWidget *centralwidget;
    QPushButton *pushButtonStart;
    QPushButton *pushButtonStartOver;
    QLabel *labelShowTerm;
    QGroupBox *groupBox;
    QFrame *line;
    QLabel *labelTerm;
    QLabel *labelAddNewTerm;
    QLabel *labelDefinition;
    QLineEdit *lineEditInputTerm;
    QLineEdit *lineEditInputDefinition;
    QPushButton *pushButtonAddNewTerm;
    QGroupBox *groupBoxSummary;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *UserAnswer;
    QLabel *labelUserAnswer;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *CorrectMessage;
    QLabel *labelCorrectMessage;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *UsersGrade;
    QLabel *labelUsersGrade;
    QPushButton *pushButtonNext;
    QFrame *line_3;
    QGroupBox *groupBoxInput;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEditInputAnswer;
    QPushButton *pushButtonShowAnswer;
    QMenuBar *menubar;
    QMenu *menuPlik;
    QMenu *menuEdycja;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(785, 592);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon);
        actionOpenDatabase = new QAction(MainWindow);
        actionOpenDatabase->setObjectName(QString::fromUtf8("actionOpenDatabase"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpenDatabase->setIcon(icon1);
        actionAddNewDatabase = new QAction(MainWindow);
        actionAddNewDatabase->setObjectName(QString::fromUtf8("actionAddNewDatabase"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddNewDatabase->setIcon(icon2);
        actionDeleteTerm = new QAction(MainWindow);
        actionDeleteTerm->setObjectName(QString::fromUtf8("actionDeleteTerm"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/trash.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDeleteTerm->setIcon(icon3);
        toolBarDeleteTerm = new QAction(MainWindow);
        toolBarDeleteTerm->setObjectName(QString::fromUtf8("toolBarDeleteTerm"));
        toolBarDeleteTerm->setIcon(icon3);
        toolBarAddNewDatabase = new QAction(MainWindow);
        toolBarAddNewDatabase->setObjectName(QString::fromUtf8("toolBarAddNewDatabase"));
        toolBarAddNewDatabase->setIcon(icon2);
        toolBarOpenDatabase = new QAction(MainWindow);
        toolBarOpenDatabase->setObjectName(QString::fromUtf8("toolBarOpenDatabase"));
        toolBarOpenDatabase->setIcon(icon1);
        actionSaveDatabase = new QAction(MainWindow);
        actionSaveDatabase->setObjectName(QString::fromUtf8("actionSaveDatabase"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaveDatabase->setIcon(icon4);
        toolBarSaveDatabase = new QAction(MainWindow);
        toolBarSaveDatabase->setObjectName(QString::fromUtf8("toolBarSaveDatabase"));
        toolBarSaveDatabase->setIcon(icon4);
        actionSaveSession = new QAction(MainWindow);
        actionSaveSession->setObjectName(QString::fromUtf8("actionSaveSession"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/session.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaveSession->setIcon(icon5);
        toolBarSaveSession = new QAction(MainWindow);
        toolBarSaveSession->setObjectName(QString::fromUtf8("toolBarSaveSession"));
        toolBarSaveSession->setIcon(icon5);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButtonStart = new QPushButton(centralwidget);
        pushButtonStart->setObjectName(QString::fromUtf8("pushButtonStart"));
        pushButtonStart->setGeometry(QRect(22, 12, 93, 28));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(10);
        pushButtonStart->setFont(font);
        pushButtonStartOver = new QPushButton(centralwidget);
        pushButtonStartOver->setObjectName(QString::fromUtf8("pushButtonStartOver"));
        pushButtonStartOver->setEnabled(true);
        pushButtonStartOver->setGeometry(QRect(122, 12, 126, 28));
        pushButtonStartOver->setFont(font);
        labelShowTerm = new QLabel(centralwidget);
        labelShowTerm->setObjectName(QString::fromUtf8("labelShowTerm"));
        labelShowTerm->setEnabled(true);
        labelShowTerm->setGeometry(QRect(36, 100, 481, 36));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        labelShowTerm->setFont(font1);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(550, 60, 211, 421));
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        line = new QFrame(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 90, 189, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        labelTerm = new QLabel(groupBox);
        labelTerm->setObjectName(QString::fromUtf8("labelTerm"));
        labelTerm->setGeometry(QRect(11, 139, 191, 20));
        labelTerm->setFont(font);
        labelTerm->setLayoutDirection(Qt::LeftToRight);
        labelAddNewTerm = new QLabel(groupBox);
        labelAddNewTerm->setObjectName(QString::fromUtf8("labelAddNewTerm"));
        labelAddNewTerm->setGeometry(QRect(10, 40, 191, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(14);
        labelAddNewTerm->setFont(font2);
        labelDefinition = new QLabel(groupBox);
        labelDefinition->setObjectName(QString::fromUtf8("labelDefinition"));
        labelDefinition->setGeometry(QRect(10, 250, 191, 20));
        labelDefinition->setFont(font);
        lineEditInputTerm = new QLineEdit(groupBox);
        lineEditInputTerm->setObjectName(QString::fromUtf8("lineEditInputTerm"));
        lineEditInputTerm->setGeometry(QRect(10, 170, 191, 22));
        lineEditInputDefinition = new QLineEdit(groupBox);
        lineEditInputDefinition->setObjectName(QString::fromUtf8("lineEditInputDefinition"));
        lineEditInputDefinition->setGeometry(QRect(10, 280, 191, 22));
        pushButtonAddNewTerm = new QPushButton(groupBox);
        pushButtonAddNewTerm->setObjectName(QString::fromUtf8("pushButtonAddNewTerm"));
        pushButtonAddNewTerm->setGeometry(QRect(10, 360, 191, 51));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial"));
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setUnderline(false);
        font3.setWeight(50);
        pushButtonAddNewTerm->setFont(font3);
        groupBoxSummary = new QGroupBox(centralwidget);
        groupBoxSummary->setObjectName(QString::fromUtf8("groupBoxSummary"));
        groupBoxSummary->setGeometry(QRect(20, 260, 481, 221));
        widget = new QWidget(groupBoxSummary);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 38, 431, 21));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        UserAnswer = new QLabel(widget);
        UserAnswer->setObjectName(QString::fromUtf8("UserAnswer"));
        UserAnswer->setEnabled(true);
        UserAnswer->setFont(font);

        horizontalLayout_2->addWidget(UserAnswer);

        labelUserAnswer = new QLabel(widget);
        labelUserAnswer->setObjectName(QString::fromUtf8("labelUserAnswer"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Arial"));
        font4.setPointSize(10);
        font4.setBold(true);
        font4.setItalic(true);
        font4.setWeight(75);
        labelUserAnswer->setFont(font4);

        horizontalLayout_2->addWidget(labelUserAnswer);

        widget1 = new QWidget(groupBoxSummary);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(30, 80, 431, 21));
        horizontalLayout_3 = new QHBoxLayout(widget1);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        CorrectMessage = new QLabel(widget1);
        CorrectMessage->setObjectName(QString::fromUtf8("CorrectMessage"));
        CorrectMessage->setEnabled(true);
        CorrectMessage->setFont(font);

        horizontalLayout_3->addWidget(CorrectMessage);

        labelCorrectMessage = new QLabel(widget1);
        labelCorrectMessage->setObjectName(QString::fromUtf8("labelCorrectMessage"));
        labelCorrectMessage->setFont(font4);

        horizontalLayout_3->addWidget(labelCorrectMessage);

        widget2 = new QWidget(groupBoxSummary);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(30, 120, 431, 21));
        horizontalLayout_5 = new QHBoxLayout(widget2);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        UsersGrade = new QLabel(widget2);
        UsersGrade->setObjectName(QString::fromUtf8("UsersGrade"));
        UsersGrade->setFont(font);

        horizontalLayout_5->addWidget(UsersGrade);

        labelUsersGrade = new QLabel(widget2);
        labelUsersGrade->setObjectName(QString::fromUtf8("labelUsersGrade"));
        labelUsersGrade->setFont(font4);

        horizontalLayout_5->addWidget(labelUsersGrade);

        pushButtonNext = new QPushButton(centralwidget);
        pushButtonNext->setObjectName(QString::fromUtf8("pushButtonNext"));
        pushButtonNext->setGeometry(QRect(190, 420, 131, 51));
        pushButtonNext->setFont(font);
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(20, 50, 521, 20));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        groupBoxInput = new QGroupBox(centralwidget);
        groupBoxInput->setObjectName(QString::fromUtf8("groupBoxInput"));
        groupBoxInput->setGeometry(QRect(20, 160, 481, 80));
        widget3 = new QWidget(groupBoxInput);
        widget3->setObjectName(QString::fromUtf8("widget3"));
        widget3->setGeometry(QRect(10, 30, 461, 30));
        horizontalLayout = new QHBoxLayout(widget3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lineEditInputAnswer = new QLineEdit(widget3);
        lineEditInputAnswer->setObjectName(QString::fromUtf8("lineEditInputAnswer"));
        lineEditInputAnswer->setEnabled(true);
        lineEditInputAnswer->setFont(font);

        horizontalLayout->addWidget(lineEditInputAnswer);

        pushButtonShowAnswer = new QPushButton(widget3);
        pushButtonShowAnswer->setObjectName(QString::fromUtf8("pushButtonShowAnswer"));
        pushButtonShowAnswer->setEnabled(true);
        pushButtonShowAnswer->setFont(font);

        horizontalLayout->addWidget(pushButtonShowAnswer);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 785, 26));
        menuPlik = new QMenu(menubar);
        menuPlik->setObjectName(QString::fromUtf8("menuPlik"));
        menuEdycja = new QMenu(menubar);
        menuEdycja->setObjectName(QString::fromUtf8("menuEdycja"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuPlik->menuAction());
        menubar->addAction(menuEdycja->menuAction());
        menuPlik->addAction(actionOpenDatabase);
        menuPlik->addAction(actionAddNewDatabase);
        menuPlik->addAction(actionSaveDatabase);
        menuPlik->addSeparator();
        menuPlik->addAction(actionExit);
        menuEdycja->addAction(actionDeleteTerm);
        toolBar->addAction(toolBarOpenDatabase);
        toolBar->addAction(toolBarSaveDatabase);
        toolBar->addAction(toolBarAddNewDatabase);
        toolBar->addAction(toolBarDeleteTerm);
        toolBar->addAction(toolBarSaveSession);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Fiszki @ 2020", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Zako\305\204cz", nullptr));
        actionOpenDatabase->setText(QCoreApplication::translate("MainWindow", "Otw\303\263rz istniej\304\205c\304\205 baz\304\231", nullptr));
        actionAddNewDatabase->setText(QCoreApplication::translate("MainWindow", "Dodaj now\304\205 baz\304\231", nullptr));
        actionDeleteTerm->setText(QCoreApplication::translate("MainWindow", "Usu\305\204 has\305\202o", nullptr));
        toolBarDeleteTerm->setText(QCoreApplication::translate("MainWindow", "Usu\305\204 has\305\202o", nullptr));
        toolBarAddNewDatabase->setText(QCoreApplication::translate("MainWindow", "Dodaj now\304\205 baz\304\231", nullptr));
        toolBarOpenDatabase->setText(QCoreApplication::translate("MainWindow", "Otw\303\263rz istniej\304\205c\304\205 baz\304\231", nullptr));
        actionSaveDatabase->setText(QCoreApplication::translate("MainWindow", "Zapisz baz\304\231", nullptr));
        toolBarSaveDatabase->setText(QCoreApplication::translate("MainWindow", "Zapisz baz\304\231", nullptr));
        actionSaveSession->setText(QCoreApplication::translate("MainWindow", "Zapisz sesj\304\231", nullptr));
        toolBarSaveSession->setText(QCoreApplication::translate("MainWindow", "Zapisz sesj\304\231", nullptr));
        pushButtonStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        pushButtonStartOver->setText(QCoreApplication::translate("MainWindow", "Zacznij od nowa", nullptr));
        labelShowTerm->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">TextLabel</p></body></html>", nullptr));
        groupBox->setTitle(QString());
        labelTerm->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Has\305\202o</p></body></html>", nullptr));
        labelAddNewTerm->setText(QCoreApplication::translate("MainWindow", "Dodaj nowe has\305\202o", nullptr));
        labelDefinition->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Odpowied\305\272</p></body></html>", nullptr));
        pushButtonAddNewTerm->setText(QCoreApplication::translate("MainWindow", "Dodaj", nullptr));
        groupBoxSummary->setTitle(QCoreApplication::translate("MainWindow", "Podsumowanie", nullptr));
        UserAnswer->setText(QCoreApplication::translate("MainWindow", "Twoja odpowied\305\272: ", nullptr));
        labelUserAnswer->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        CorrectMessage->setText(QCoreApplication::translate("MainWindow", "Poprawna odpowied\305\272:", nullptr));
        labelCorrectMessage->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        UsersGrade->setText(QCoreApplication::translate("MainWindow", "Twoja ocena:", nullptr));
        labelUsersGrade->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButtonNext->setText(QCoreApplication::translate("MainWindow", "Dalej", nullptr));
        groupBoxInput->setTitle(QCoreApplication::translate("MainWindow", "Wpisz odpowied\305\272", nullptr));
        pushButtonShowAnswer->setText(QCoreApplication::translate("MainWindow", "Poka\305\274 odpowied\305\272", nullptr));
        menuPlik->setTitle(QCoreApplication::translate("MainWindow", "Plik", nullptr));
        menuEdycja->setTitle(QCoreApplication::translate("MainWindow", "Edycja", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
