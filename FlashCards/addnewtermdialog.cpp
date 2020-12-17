#include "ui_addnewtermdialog.h"
#include "addnewtermdialog.h"


AddNewTermDialog::AddNewTermDialog(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::AddNewTermDialog)
{
    ui->setupUi(this);
}

AddNewTermDialog::~AddNewTermDialog()
{
    delete ui;
}

void AddNewTermDialog::on_pushButtonAddNewTerm_clicked()
{
    std::string term{};
    term = ui->lineEditInputTerm->text().toStdString();
    std::string def{};
    def = ui->lineEditInputDefinition->text().toStdString();
    Card card{term, def};
    ui->lineEditInputTerm->clear();
    ui->lineEditInputDefinition->clear();
    ui->pushButtonAddNewTerm->setDisabled(true);
    emit createdNewTerm(card);
}

void AddNewTermDialog::on_lineEditInputTerm_textEdited()
{
    std::string term = ui->lineEditInputTerm->text().toStdString();
    std::string definition = ui->lineEditInputDefinition->text().toStdString();
    if(term != "" &&  definition != "") {
        ui->pushButtonAddNewTerm->setDisabled(false);
    }
    else {
        ui->pushButtonAddNewTerm->setDisabled(true);
    }
}

void AddNewTermDialog::on_lineEditInputDefinition_textEdited()
{
    if(ui->lineEditInputTerm->text() != "" && ui->lineEditInputDefinition->text().toStdString() != "") {
        ui->pushButtonAddNewTerm->setDisabled(false);
    }
    else {
        ui->pushButtonAddNewTerm->setDisabled(true);
    }
}
