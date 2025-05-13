#include "employeeswindow.h"
#include "ui_employeeswindow.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlTableModel>

EmployeesWindow::EmployeesWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EmployeesWindow)
{
    ui->setupUi(this);

    employeeModel = new QSqlTableModel(this);
    employeeModel->setTable("users");
    employeeModel->setFilter("role = 'employee'");
    employeeModel->select();

    employeeModel->setHeaderData(1, Qt::Horizontal, "Login");
    employeeModel->setHeaderData(4, Qt::Horizontal, "Imię");
    employeeModel->setHeaderData(5, Qt::Horizontal, "Nazwisko");
    employeeModel->setHeaderData(6, Qt::Horizontal, "Email");

    ui->employeesTableView->setModel(employeeModel);
    ui->employeesTableView->hideColumn(0); // id
    ui->employeesTableView->hideColumn(2); // hasło
    ui->employeesTableView->hideColumn(3); // rola

}

EmployeesWindow::~EmployeesWindow()
{
    delete ui;
}

void EmployeesWindow::on_addEmployeeButton_clicked()
{
    QString imie = ui->firstNameLineEdit->text();
    QString nazwisko = ui->lastNameLineEdit->text();
    QString email = ui->emailLineEdit->text();
    QString login = ui->usernameLineEdit->text();
    QString haslo = ui->passwordLineEdit->text();

    if (imie.isEmpty() || nazwisko.isEmpty() || email.isEmpty() || login.isEmpty() || haslo.isEmpty()) {
        QMessageBox::warning(this, "Błąd", "Wypełnij wszystkie pola.");
        return;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password, role, first_name, last_name, email) "
                  "VALUES (:username, :password, 'employee', :first_name, :last_name, :email)");
    query.bindValue(":username", login);
    query.bindValue(":password", haslo);
    query.bindValue(":first_name", imie);
    query.bindValue(":last_name", nazwisko);
    query.bindValue(":email", email);

    if (!query.exec()) {
        QMessageBox::critical(this, "Błąd", "Nie udało się dodać pracownika: " + query.lastError().text());
    } else {
        QMessageBox::information(this, "Sukces", "Pracownik dodany pomyślnie!");
        ui->firstNameLineEdit->clear();
        ui->lastNameLineEdit->clear();
        ui->emailLineEdit->clear();
        ui->usernameLineEdit->clear();
        ui->passwordLineEdit->clear();
        employeeModel->select();
    }
}

void EmployeesWindow::on_deleteEmployeeButton_clicked()
{
    int row = ui->employeesTableView->currentIndex().row();

    if (row < 0) {
        QMessageBox::warning(this, "Błąd", "Nie wybrano żadnego pracownika do usunięcia.");
        return;
    }

    QString employeeLogin = employeeModel->data(employeeModel->index(row, 1)).toString();

    if (QMessageBox::question(this, "Potwierdzenie",
                              "Czy na pewno chcesz usunąć pracownika: " + employeeLogin + "?") == QMessageBox::Yes)
    {
        employeeModel->removeRow(row);
        if (!employeeModel->submitAll()) {
            QMessageBox::critical(this, "Błąd", "Nie udało się usunąć pracownika: " + employeeModel->lastError().text());
            employeeModel->revertAll();
        } else {
            employeeModel->select();
        }
    }
}
