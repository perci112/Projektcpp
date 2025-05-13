#include "subjectswindow.h"
#include "ui_subjectswindow.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>

SubjectsWindow::SubjectsWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SubjectsWindow)
{
    ui->setupUi(this);
    loadDirections(); // <--- Ładowanie kierunków
     loadCoordinators();
    loadSubjects();   // <--- Jeśli masz
}

SubjectsWindow::~SubjectsWindow()
{
    delete ui;
}

void SubjectsWindow::loadSubjects()
{
    subjectModel = new QSqlTableModel(this);
    subjectModel->setTable("subjects");
    subjectModel->select();

    subjectModel->setHeaderData(1, Qt::Horizontal, "Nazwa");
    subjectModel->setHeaderData(2, Qt::Horizontal, "Opis");

    ui->subjectsTableView->setModel(subjectModel);
    ui->subjectsTableView->hideColumn(0); // ukryj id
}
void SubjectsWindow::loadDirections() {
    QSqlQuery query("SELECT id, name FROM directions");
    ui->directionComboBox->clear();
    while (query.next()) {
        ui->directionComboBox->addItem(query.value(1).toString(), query.value(0).toInt());
    }
}
void SubjectsWindow::loadCoordinators() {
    QSqlQuery query("SELECT id, first_name, last_name FROM users WHERE role = 'employee'");
    ui->coordinatorComboBox->clear();
    while (query.next()) {
        QString coordinatorName = query.value(1).toString() + " " + query.value(2).toString();
        ui->coordinatorComboBox->addItem(coordinatorName, query.value(0).toInt());
    }
}

void SubjectsWindow::on_addSubjectButton_clicked() {
    QString name = ui->nameLineEdit->text();
    QString description = ui->descriptionLineEdit->text();
    int directionId = ui->directionComboBox->currentData().toInt();
    int coordinatorId = ui->coordinatorComboBox->currentData().toInt();  // Pobieranie ID koordynatora

    if (name.isEmpty()) {
        QMessageBox::warning(this, "Błąd", "Nazwa przedmiotu nie może być pusta.");
        return;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO subjects (name, description, direction_id, coordinator_id) "
                  "VALUES (:name, :description, :direction_id, :coordinator_id)");
    query.bindValue(":name", name);
    query.bindValue(":description", description);
    query.bindValue(":direction_id", directionId);
    query.bindValue(":coordinator_id", coordinatorId);  // Przekazanie ID koordynatora

    if (!query.exec()) {
        QMessageBox::critical(this, "Błąd", "Nie udało się dodać przedmiotu: " + query.lastError().text());
    } else {
        QMessageBox::information(this, "Sukces", "Dodano przedmiot.");
        loadSubjects(); // Odświeżenie listy po dodaniu
    }
}

void SubjectsWindow::on_deleteSubjectButton_clicked()
{
    int row = ui->subjectsTableView->currentIndex().row();

    if (row < 0) {
        QMessageBox::warning(this, "Błąd", "Nie wybrano żadnego przedmiotu do usunięcia.");
        return;
    }

    QString subjectName = subjectModel->data(subjectModel->index(row, 1)).toString();

    if (QMessageBox::question(this, "Potwierdzenie",
                              "Czy na pewno chcesz usunąć przedmiot: " + subjectName + "?") == QMessageBox::Yes)
    {
        subjectModel->removeRow(row);
        if (!subjectModel->submitAll()) {
            QMessageBox::critical(this, "Błąd", "Nie udało się usunąć przedmiotu: " + subjectModel->lastError().text());
            subjectModel->revertAll();  // cofnij zmiany w razie błędu
        } else {
            subjectModel->select(); // odśwież model po usunięciu
        }
    }
}

