#pragma once

#include <QDialog>

namespace Ui {
class SetSummaryDialog;
}

class SetSummaryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SetSummaryDialog(QWidget *parent = nullptr);
    ~SetSummaryDialog();

public slots:
    void showScore(int scoredPoints, int totalPoints);

private:
    Ui::SetSummaryDialog *ui;
};
