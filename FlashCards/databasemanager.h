#pragma once

#include "mainwindow.h"

class DataBaseManager
{
public:
    DataBaseManager(MainWindow* window);
public slots:
    bool openDatabase();
    bool addNewDatabase();
    void saveDatabase();
private:
    MainWindow* window;
};

