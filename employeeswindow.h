#ifndef EMPLOYEESWINDOW_H
#define EMPLOYEESWINDOW_H

#include <QDialog>
#include <QSqlTableModel>

namespace Ui {
class EmployeesWindow;
}

class EmployeesWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EmployeesWindow(QWidget *parent = nullptr);
    ~EmployeesWindow();

private slots:
    void on_addEmployeeButton_clicked();

    void on_deleteEmployeeButton_clicked();

private:
    Ui::EmployeesWindow *ui;
        QSqlTableModel *employeeModel;
};

#endif // EMPLOYEESWINDOW_H
