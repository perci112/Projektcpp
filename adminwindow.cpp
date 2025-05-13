#include "adminwindow.h"
#include "ui_adminwindow.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include "subjectswindow.h"
#include "employeeswindow.h"
#include "assignstudentswindow.h"

AdminWindow::AdminWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Admin)
{
    ui->setupUi(this);
     loadStudents(); // <- tutaj!
    studentModel = new QSqlTableModel(this);
    studentModel->setTable("users");
    studentModel->setFilter("role = 'student'");
    studentModel->select();

    studentModel->setHeaderData(1, Qt::Horizontal, "Login");
    studentModel->setHeaderData(4, Qt::Horizontal, "Imię");
    studentModel->setHeaderData(5, Qt::Horizontal, "Nazwisko");
    studentModel->setHeaderData(6, Qt::Horizontal, "Email");

    ui->studentsTableView->setModel(studentModel);
    ui->studentsTableView->hideColumn(0); // id
    ui->studentsTableView->hideColumn(2); // hasło
    ui->studentsTableView->hideColumn(3); // rola
    connect(ui->searchLineEdit, &QLineEdit::returnPressed, this, &AdminWindow::on_searchButton_clicked);

}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::on_addStudentButton_clicked()
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
                  "VALUES (:username, :password, 'student', :first_name, :last_name, :email)");

    query.bindValue(":username", login);
    query.bindValue(":password", haslo);
    query.bindValue(":role", "student");
    query.bindValue(":first_name", imie);
    query.bindValue(":last_name", nazwisko);
    query.bindValue(":email", email);


    if (!query.exec()) {
        QMessageBox::critical(this, "Błąd", "Nie udało się dodać studenta: " + query.lastError().text());
    } else {
        QMessageBox::information(this, "Sukces", "Student dodany pomyślnie!");
        ui->firstNameLineEdit->clear();
        ui->lastNameLineEdit->clear();
        ui->emailLineEdit->clear();
        ui->usernameLineEdit->clear();
        ui->passwordLineEdit->clear();
        loadStudents(); // odśwież widok po dodaniu

    }
}


void AdminWindow::on_addStudentButton_2_clicked()
{
    QModelIndex index = ui->studentsTableView->currentIndex();

    if (!index.isValid()) {
        QMessageBox::warning(this, "Błąd", "Nie wybrano studenta.");
        return;
    }

    int row = index.row();
    QString login = studentModel->data(studentModel->index(row, 1)).toString();

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Potwierdzenie",
                                  "Czy na pewno chcesz usunąć studenta: " + login + "?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        studentModel->removeRow(row);
        if (!studentModel->submitAll()) {
            QMessageBox::critical(this, "Błąd", "Usuwanie nie powiodło się: " + studentModel->lastError().text());
            studentModel->revertAll();
        } else {
            QMessageBox::information(this, "Sukces", "Student został usunięty.");
        }
    }
}
void AdminWindow::loadStudents()
{
    studentModel = new QSqlTableModel(this);
    studentModel->setTable("users");
    studentModel->setFilter("role = 'student'");
    studentModel->select();

    studentModel->setHeaderData(1, Qt::Horizontal, "Login");
    studentModel->setHeaderData(4, Qt::Horizontal, "Imię");
    studentModel->setHeaderData(5, Qt::Horizontal, "Nazwisko");
    studentModel->setHeaderData(6, Qt::Horizontal, "Email");

    ui->studentsTableView->setModel(studentModel);
    ui->studentsTableView->hideColumn(0); // id
    ui->studentsTableView->hideColumn(2); // hasło
    ui->studentsTableView->hideColumn(3); // rola
    ui->studentsTableView->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::SelectedClicked);

}

void AdminWindow::on_saveChanges_clicked()
{
    if (!studentModel->submitAll()) {
        QMessageBox::critical(this, "Błąd", "Nie udało się zapisać zmian.");
    } else {
        QMessageBox::information(this, "Sukces", "Zmiany zapisane.");
    }
}
void AdminWindow::on_searchButton_clicked()
{
    QString searchText = ui->searchLineEdit->text().trimmed();
    if (searchText.isEmpty()) {
        QMessageBox::warning(this, "Błąd", "Wprowadź tekst do wyszukania.");
        return;
    }

    // Szukaj po loginie lub nazwisku
    QString filter = QString("(username LIKE '%%1%' OR last_name LIKE '%%1%') AND role = 'student'")
                         .arg(searchText);
    studentModel->setFilter(filter);
    studentModel->select();
}
void AdminWindow::on_resetButton_clicked()
{
    ui->searchLineEdit->clear();
    studentModel->setFilter("role = 'student'");
    studentModel->select();
}

void AdminWindow::on_manageSubjectsButton_clicked()
{
    SubjectsWindow *sw = new SubjectsWindow(this);
    sw->exec();
}


void AdminWindow::on_manageEmployeesButton_clicked()
{
    EmployeesWindow *empWin = new EmployeesWindow(this);
    empWin->setModal(true);  // jeśli EmployeesWindow dziedziczy po QDialog
    empWin->show();
}


void AdminWindow::on_pushButton_clicked()
{
    AssignStudentsWindow *window = new AssignStudentsWindow(this);
    window->exec();
}

