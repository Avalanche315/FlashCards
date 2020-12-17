#pragma once

#include "mainwindow.h"

class SessionManager
{
public:
    SessionManager(MainWindow* window);
    void loadSession();
    void establishBasicSet();
    void saveSession();
    void readFile(std::vector<Card>& list, QString filePath);
    bool checkEditStatus();
private:
    MainWindow* window;
};

