#include "employeewindow.h"
#include "ui_employeewindow.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QDebug>
#include <QDate>

employeewindow::employeewindow(QString employeeId, QWidget *parent)
    : QDialog(parent),
    ui(new Ui::employeewindow),
    employeeId(employeeId),
    studentModel(new QSqlQueryModel(this))
{
    ui->setupUi(this);
    ui->gradeSpinBox->setMinimum(2);
    ui->gradeSpinBox->setMaximum(5);
    loadSubjects();
}

employeewindow::~employeewindow()
{
    delete ui;
}

void employeewindow::loadSubjects()
{
    QSqlQuery query;
    query.prepare("SELECT id, name FROM subjects WHERE coordinator_id = :id");
    query.bindValue(":id", employeeId);

    if (!query.exec()) {
        QMessageBox::critical(this, "Błąd", "Nie udało się pobrać przedmiotów: " + query.lastError().text());
        return;
    }

    ui->subjectComboBox->clear();
    while (query.next()) {
        ui->subjectComboBox->addItem(query.value("name").toString(), query.value("id").toInt());
    }

    if (ui->subjectComboBox->count() > 0)
        loadStudentsForSubject(ui->subjectComboBox->currentData().toInt());
}

void employeewindow::loadStudentsForSubject(int subjectId)
{
    QSqlQuery query;
    query.prepare(R"(
        SELECT users.id,
               users.first_name || ' ' || users.last_name AS full_name,
               grades.grade
        FROM users
        JOIN student_subjects ON users.id = student_subjects.student_id
        LEFT JOIN grades ON users.id = grades.student_id AND grades.subject_id = :subjectId
        WHERE student_subjects.subject_id = :subjectId
    )");
    query.bindValue(":subjectId", subjectId);

    if (!query.exec()) {
        QMessageBox::critical(this, "Błąd", "Nie udało się pobrać studentów: " + query.lastError().text());
        return;
    }

    studentModel->setQuery(query);

    studentModel->setHeaderData(1, Qt::Horizontal, "Student");
    studentModel->setHeaderData(2, Qt::Horizontal, "Ocena");

    ui->studentsTableView->setModel(studentModel);
    ui->studentsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->studentsTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->studentsTableView->hideColumn(0); // ukryj kolumnę z ID
}

void employeewindow::on_subjectComboBox_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    int subjectId = ui->subjectComboBox->currentData().toInt();
    loadStudentsForSubject(subjectId);
}

void employeewindow::on_assignGradeButton_clicked()
{
    QModelIndex selectedIndex = ui->studentsTableView->currentIndex();
    if (!selectedIndex.isValid()) {
        QMessageBox::warning(this, "Błąd", "Wybierz studenta.");
        return;
    }

    int studentId = studentModel->data(studentModel->index(selectedIndex.row(), 0)).toInt();
    int subjectId = ui->subjectComboBox->currentData().toInt();
    int grade = ui->gradeSpinBox->value();

    // Debugowanie zapytania
    qDebug() << "Student ID: " << studentId;
    qDebug() << "Subject ID: " << subjectId;
    qDebug() << "Grade: " << grade;

    QSqlQuery query;
    query.prepare(R"(
    INSERT INTO grades (student_id, subject_id, grade, date_assigned)
    VALUES (:studentId, :subjectId, :grade, :date)
    ON CONFLICT(student_id, subject_id)
    DO UPDATE SET grade = :grade, date_assigned = :date
)");
    query.bindValue(":studentId", studentId);
    query.bindValue(":subjectId", subjectId);
    query.bindValue(":grade", grade);
    query.bindValue(":date", QDate::currentDate().toString("yyyy-MM-dd"));  // <-- aktualna data


    // Debugowanie zapytania SQL
    qDebug() << "Executed Query: " << query.executedQuery();

    if (!query.exec()) {
        QMessageBox::critical(this, "Błąd", "Nie udało się przypisać oceny: " + query.lastError().text());
    } else {
        QMessageBox::information(this, "Sukces", "Ocena została przypisana.");
    }
}
