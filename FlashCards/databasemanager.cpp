#include "databasemanager.h"
#include "sessionmanager.h"
#include "cardmanager.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QInputDialog>

DataBaseManager::DataBaseManager(MainWindow* window)
    : window(window)
{

}

bool DataBaseManager::openDatabase() {
    QString fileName = QFileDialog::getOpenFileName(window,
        QString("Choose flashcard database"), "../FlashCards/Data", QString("Text files (*.txt)"));
    if(fileName != "") {
        window->filePath = fileName;
        SessionManager manager{window};
        manager.readFile(window->cardList->getList(), fileName);
        return true;
    }
   return false;
}

bool DataBaseManager::addNewDatabase() {
    QString path = QInputDialog::getText(window, "Create new data base", "Input flashcards database name");
    if (path != "") {
        path = "../FlashCards/Data/" + path + ".txt";
        QFile file{path};

        if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
            QTextStream out(&file);
            out << "";
            file.close();
        }
        window->filePath = path;
        SessionManager manager{window};
        manager.readFile(window->cardList->getList(), window->filePath);
        window->editStatus = true;
        window->on_actionAdd_new_terms_triggered();
        return true;
    }
    return false;
}

void DataBaseManager::saveDatabase() {
    QFile file{window->filePath};
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream out(&file);
        for(auto& it : window->cardList->getList()) {
            QString term = QString::fromStdString(it.getTerm());
            QString def = QString::fromStdString(it.getDef());
            out << term << "\n" << def << "\n";
        }
        file.close();
    }
}
