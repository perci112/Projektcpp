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

private slots:
    void on_pushButton_clicked();

private:
    Ui::studentwindow *ui;
    QString studentUsername;

    QSqlQueryModel *attendanceModel;

    void loadStudentInfo();
    void loadGrades();
    void loadAttendance();
    double calculateAverageGrade(int studentId);
    int getStudentIdByUsername(const QString &username);
};

#endif // STUDENTWINDOW_H
