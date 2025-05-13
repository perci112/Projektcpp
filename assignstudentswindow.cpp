#include "assignstudentswindow.h"
#include "ui_assignstudentswindow.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QTableView>
#include <QSqlTableModel>

AssignStudentsWindow::AssignStudentsWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AssignStudentsWindow)
{
    ui->setupUi(this);
    loadDirections();
    loadStudents();
}

AssignStudentsWindow::~AssignStudentsWindow()
{
    delete ui;
}

void AssignStudentsWindow::loadDirections()
{
    QSqlQuery query("SELECT * FROM directions");

    ui->comboBoxDirections->clear();

    while (query.next()) {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        ui->comboBoxDirections->addItem(name, id);
    }

    if (ui->comboBoxDirections->count() == 0) {
        QMessageBox::warning(this, "Błąd", "Brak dostępnych kierunków!");
    }
}

void AssignStudentsWindow::loadStudents()
{
    // Użycie QSqlTableModel do wyświetlania studentów w tabeli
    QSqlTableModel *studentModel = new QSqlTableModel(this);
    studentModel->setTable("users");
    studentModel->setFilter("role = 'student'");
    studentModel->select();

    studentModel->setHeaderData(1, Qt::Horizontal, "Imię");
    studentModel->setHeaderData(2, Qt::Horizontal, "Nazwisko");

    ui->studentsTableView->setModel(studentModel);
    ui->studentsTableView->hideColumn(0); // ukrycie ID
    ui->studentsTableView->setEditTriggers(QAbstractItemView::NoEditTriggers); // Zablokowanie edycji
}

void AssignStudentsWindow::on_assignButton_clicked()
{
    // Pobierz wybranego studenta z tabeli
    QModelIndexList selectedRows = ui->studentsTableView->selectionModel()->selectedRows();
    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, "Błąd", "Nie wybrano studenta.");
        return;
    }

    int studentId = selectedRows.first().data().toInt(); // Pobierz ID studenta z pierwszej wybranej komórki

    // Pobierz wybrany kierunek z comboboxa
    int directionId = ui->comboBoxDirections->currentData().toInt();
    if (directionId == 0) {
        QMessageBox::warning(this, "Błąd", "Nie wybrano kierunku.");
        return;
    }

    // Przygotowanie zapytania SQL, aby pobrać przedmioty z wybranego kierunku
    QSqlQuery query;
    query.prepare("SELECT id FROM subjects WHERE direction_id = :direction_id");
    query.bindValue(":direction_id", directionId);

    if (!query.exec()) {
        QMessageBox::critical(this, "Błąd", "Nie udało się pobrać przedmiotów: " + query.lastError().text());
        return;
    }

    // Przypisanie studenta do wszystkich przedmiotów z danego kierunku
    while (query.next()) {
        int subjectId = query.value(0).toInt(); // Pobierz ID przedmiotu

        QSqlQuery insertQuery;
        insertQuery.prepare("INSERT INTO student_subjects (student_id, subject_id) VALUES (:student_id, :subject_id)");

        qDebug() << "Student ID: " << studentId << " Subject ID: " << subjectId;  // debugowanie

        // Dodanie sprawdzenia, co jest przygotowywane do zapytania
        qDebug() << "Prepared Query: " << insertQuery.executedQuery();

        insertQuery.bindValue(":student_id", studentId);
        insertQuery.bindValue(":subject_id", subjectId);

        if (!insertQuery.exec()) {
            QMessageBox::critical(this, "Błąd", "Nie udało się przypisać przedmiotu: " + insertQuery.lastError().text());
            return;
        }

        qDebug() << "Przypisanie przedmiotu zakończone sukcesem!";


    }

    // Informacja o sukcesie
    QMessageBox::information(this, "Sukces", "Student przypisany do kierunku i przedmiotów.");
    loadStudents(); // Odśwież tabelę studentów
}


