#pragma once

#include <QDialog>
#include "Card.h"

namespace Ui {
class AddNewTermDialog;
}

class AddNewTermDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewTermDialog(QWidget *parent = nullptr);
    ~AddNewTermDialog();

signals:
    void createdNewTerm(Card& card);

private slots:
    void on_lineEditInputTerm_textEdited();
    void on_lineEditInputDefinition_textEdited();
    void on_pushButtonAddNewTerm_clicked();

private:
    Ui::AddNewTermDialog *ui;
};

