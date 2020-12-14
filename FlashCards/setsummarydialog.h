#ifndef SETSUMMARYDIALOG_H
#define SETSUMMARYDIALOG_H

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

#endif // SETSUMMARYDIALOG_H
