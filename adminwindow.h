#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>
#include <QSqlTableModel>

namespace Ui {
class Admin;
}

class AdminWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr);
    ~AdminWindow();

private slots:
    void on_addStudentButton_clicked();

    void on_addStudentButton_2_clicked();

    void on_saveChanges_clicked();
    void on_searchButton_clicked();
    void on_resetButton_clicked();

    void on_manageSubjectsButton_clicked();

    void on_manageEmployeesButton_clicked();


    void on_pushButton_clicked();

private:
    Ui::Admin *ui;
    QSqlTableModel *studentModel;
    void loadStudents();

};

#endif // ADMINWINDOW_H
