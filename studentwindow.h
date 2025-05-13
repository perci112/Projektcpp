#ifndef STUDENTWINDOW_H
#define STUDENTWINDOW_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class studentwindow;
}

class studentwindow : public QDialog
{
    Q_OBJECT

public:
    explicit studentwindow(const QString &username, QWidget *parent = nullptr);
    ~studentwindow();

private:
    Ui::studentwindow *ui;
    QString studentUsername;

    void loadStudentInfo();
    void loadGrades();
    int getStudentIdByUsername(const QString &username);
};

#endif // STUDENTWINDOW_H
