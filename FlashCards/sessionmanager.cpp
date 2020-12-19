#include "sessionmanager.h"
#include "additionalfunctions.h"
#include <QFile>
#include <QFileInfo>
#include <QDebug>
#include <QMessageBox>

SessionManager::SessionManager(MainWindow* window) : window(window)
{

}

void SessionManager::loadSession(){
    checkEditStatus();
    QFile file{"../FlashCards/Data/session.txt"};

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error with loading the file: " << file.errorString();
        return;
    }
    else {
        std::string fileName = file.readLine().toStdString();
        AdditionalFunctions::removeWhiteSpace(fileName);
        window->filePath = QString::fromStdString(fileName);
        QString name = QString::fromStdString(fileName);
        readFile(window->cardList->getList(), name);
        window->cardList->setIndex(file.readLine().toInt());
        window->cardList->setPoints(file.readLine().toInt());
        window->beginSet(window->cardList->getIndex());
    }
    file.close();
}

void SessionManager::establishBasicSet() {
    QString sessionFile("../FlashCards/Data/session.txt");
    if(QFileInfo::exists(sessionFile)) {
        int ret = QMessageBox::information(window, "A saved session has been detected",
                                           "Do you want to load saved session?",
                                           QMessageBox::No, QMessageBox::Yes);
        if (ret == QMessageBox::Yes) {
            loadSession();
        }
        else {
            // removing session file
            QFile sFile(sessionFile);
            sFile.remove();
            // establish default database
            window->filePath = "../FlashCards/Data/PLtoENG.txt";
            readFile(window->cardList->getList(), window->filePath);
            window->beginSet();
        }
    }
    else {
        int ret = QMessageBox::information(window, "",
                                           "Do you want to load the default database?",
                                           QMessageBox::No, QMessageBox::Yes);
        if (ret == QMessageBox::Yes) {
            window->filePath = "../FlashCards/Data/PLtoENG.txt";
            readFile(window->cardList->getList(), window->filePath);
        }
        else {
            window->on_actionOpenDatabase_triggered();
        }
        window->beginSet();
    }
}

void SessionManager::saveSession() {
    if(window->cardList->getIndex() > 1) {
        QFile file{"../FlashCards/Data/session.txt"};
        if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
            QTextStream out(&file);
            out << window->filePath
                << "\n" << window->cardList->getIndex()
                << "\n" << window->cardList->getPoints();
            file.close();
        }
    }
}


void SessionManager::readFile(std::vector<Card>& list, QString filePath) {
    list.clear();

    window->cardList->setIndex(0);

    QFile file{filePath};

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error with loading the file: " << file.errorString();
        return;
    }

    while (!file.atEnd()) {
        std::string term = file.readLine().toStdString();
        AdditionalFunctions::removeWhiteSpace(term);
        std::string def = file.readLine().toStdString();
        AdditionalFunctions::removeWhiteSpace(def);
        list.push_back(Card(term, def));
    }

    file.close();

    window->showStatusBar();
    if(window->cardList->size() == 0) {
        window->deactivateStartButton();
    }
}

bool SessionManager::checkEditStatus() {
    // 1 - quit
    // 0 - do not quit
    if(window->editStatus == true) {
        int ret = QMessageBox::warning(window, "Warning!",
                                           "You've edited the current set. Do you want to save it?",
                                           QMessageBox::No, QMessageBox::Yes, QMessageBox::Cancel);
        if (ret == QMessageBox::Yes) {
            window->on_actionSaveDatabase_triggered();
            if(window->cardList->getIndex() > 1)
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
