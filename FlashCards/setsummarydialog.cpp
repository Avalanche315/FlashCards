#include "setsummarydialog.h"
#include "ui_setsummarydialog.h"
#include "mainwindow.h"

SetSummaryDialog::SetSummaryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetSummaryDialog)
{
    ui->setupUi(this);
}

void SetSummaryDialog::showScore(int scoredPoints, int totalPoints) {
    int score = scoredPoints / static_cast<double>(totalPoints) * 100;
    ui->showScoreLabel->setText("Correct answers: " + QString::number(scoredPoints) + "/" + QString::number(totalPoints)
                         + " (" + QString::number(score) + "%)");
}

SetSummaryDialog::~SetSummaryDialog()
{
    delete ui;
}
