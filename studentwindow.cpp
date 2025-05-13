#include "studentwindow.h"
#include "ui_studentwindow.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlQueryModel>

studentwindow::studentwindow(const QString &username, QWidget *parent)
    : QDialog(parent),
    ui(new Ui::studentwindow),
    studentUsername(username)
{
    ui->setupUi(this);
    ui->gradesTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->gradesTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    loadStudentInfo();
    loadGrades();
}

studentwindow::~studentwindow()
{
    delete ui;
}

void studentwindow::loadStudentInfo()
{
    QSqlQuery query;
    query.prepare("SELECT first_name, last_name, email FROM users WHERE username = :username");
    query.bindValue(":username", studentUsername);

    if (!query.exec()) {
        QMessageBox::critical(this, "Błąd", "Nie udało się pobrać danych studenta: " + query.lastError().text());
        return;
    }

    if (query.next()) {
        ui->firstNameLabel->setText(query.value("first_name").toString());
        ui->lastNameLabel->setText(query.value("last_name").toString());
        ui->emailLabel->setText(query.value("email").toString());
    }
}

void studentwindow::loadGrades()
{
    int studentId = getStudentIdByUsername(studentUsername);

    QSqlQuery query;
    query.prepare(R"(
        SELECT subjects.name, grades.grade
        FROM grades
        JOIN subjects ON grades.subject_id = subjects.id
        WHERE grades.student_id = :studentId
    )");
    query.bindValue(":studentId", studentId);

    if (!query.exec()) {
        QMessageBox::critical(this, "Błąd", "Nie udało się pobrać ocen: " + query.lastError().text());
        return;
    }

    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery(query);
    ui->gradesTableView->setModel(model);
}

int studentwindow::getStudentIdByUsername(const QString &username)
{
    QSqlQuery query;
    query.prepare("SELECT id FROM users WHERE username = :username");
    query.bindValue(":username", username);

    if (!query.exec()) {
        QMessageBox::critical(this, "Błąd", "Nie udało się pobrać ID studenta: " + query.lastError().text());
        return -1;
    }

    if (query.next()) {
        return query.value(0).toInt();
    }

    return -1;
}
