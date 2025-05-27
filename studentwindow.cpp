#include "studentwindow.h"
#include "ui_studentwindow.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QStandardItemModel>
#include <QStandardItem>

studentwindow::studentwindow(const QString &username, QWidget *parent)
    : QDialog(parent),
    ui(new Ui::studentwindow),
    studentUsername(username)
{
    ui->setupUi(this);
    ui->gradesTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->gradesTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    attendanceModel = new QSqlQueryModel(this);
    ui->attendanceTableView->setModel(attendanceModel);
    loadAttendance();
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
    qDebug() << "Student ID:" << studentId;

    if (!query.exec()) {
        QMessageBox::critical(this, "Błąd", "Nie udało się pobrać ocen: " + query.lastError().text());
        return;
    }

    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery(std::move(query));
    ui->gradesTableView->setModel(model);

    double avg = calculateAverageGrade(studentId);
    ui->averageLabel->setText(QString("Średnia ocen: %1").arg(avg, 0, 'f', 2));

    // Informacja o stypendium
    QString stipendStatus = (avg >= 4.0) ? "Tak" : "Nie";
    ui->stipendLabel->setText("Stypendium naukowe: " + stipendStatus);
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
double studentwindow::calculateAverageGrade(int studentId)
{
    QSqlQuery query;
    query.prepare("SELECT AVG(grade) FROM grades WHERE student_id = :studentId;");
    query.bindValue(":studentId", studentId);

    if (!query.exec()) {
        QMessageBox::critical(this, "Błąd", "Nie udało się obliczyć średniej: " + query.lastError().text());
        return 0.0;
    }

    if (query.next()) {
        QVariant val = query.value(0);
        qDebug() << "Średnia z bazy:" << val;
        if (val.isValid() && !val.isNull()) {
            return val.toDouble();
        }
    }

    return 0.0;
}



void studentwindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Zapisz jako CSV", "", "CSV Files (*.csv)");
    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Błąd", "Nie można zapisać pliku.");
        return;
    }

    QTextStream out(&file);

    // Nagłówki
    out << "Przedmiot,Ocena\n";

    // Pobieranie ocen
    int studentId = getStudentIdByUsername(studentUsername);
    QSqlQuery query;
    query.prepare(R"(
        SELECT subjects.name, grades.grade
        FROM grades
        JOIN subjects ON grades.subject_id = subjects.id
        WHERE grades.student_id = :studentId
    )");
    query.bindValue(":studentId", studentId);

    if (query.exec()) {
        while (query.next()) {
            QString subject = query.value(0).toString();
            double grade = query.value(1).toDouble();
            out << subject << "," << grade << "\n";
        }
    } else {
        QMessageBox::warning(this, "Błąd", "Nie udało się pobrać ocen: " + query.lastError().text());
    }

    // Średnia
    double avg = calculateAverageGrade(studentId);
    out << "\nŚrednia ocen:," << QString::number(avg, 'f', 2) << "\n";

    // Stypendium
    QString hasScholarship = (avg >= 4.0) ? "TAK" : "NIE";
    out << "Stypendium:," << hasScholarship << "\n";

    file.close();
    QMessageBox::information(this, "Sukces", "Dane zostały wyeksportowane do pliku CSV.");
}

void studentwindow::loadAttendance()
{
    int studentId = getStudentIdByUsername(studentUsername);
    if (studentId == -1) {
        QMessageBox::warning(this, "Błąd", "Nie znaleziono studenta.");
        return;
    }

    QSqlQuery scheduleQuery;
    scheduleQuery.prepare(R"(
        SELECT s.id, s.name, sc.weekday, sc.every_two_weeks, sc.start_date
        FROM subjects s
        JOIN schedule sc ON s.id = sc.subject_id
        JOIN student_subjects ss ON ss.subject_id = s.id
        WHERE ss.student_id = :studentId
    )");
    scheduleQuery.bindValue(":studentId", studentId);

    if (!scheduleQuery.exec()) {
        QMessageBox::critical(this, "Błąd", "Nie udało się pobrać harmonogramu: " + scheduleQuery.lastError().text());
        return;
    }

    struct AttendanceEntry {
        QString subjectName;
        QDate date;
        QString status;
    };

    QList<AttendanceEntry> attendanceList;
    QDate today = QDate::currentDate();

    while (scheduleQuery.next()) {
        int subjectId = scheduleQuery.value(0).toInt();
        QString subjectName = scheduleQuery.value(1).toString();
        int weekday = scheduleQuery.value(2).toInt();
        bool everyTwoWeeks = scheduleQuery.value(3).toBool();
        QDate startDate = scheduleQuery.value(4).toDate();

        // Dopasuj startDate do pierwszego właściwego dnia tygodnia
        QDate currentDate = startDate;
        while (currentDate.dayOfWeek() != weekday) {
            currentDate = currentDate.addDays(1);
        }

        int intervalDays = everyTwoWeeks ? 14 : 7;

        while (currentDate <= today) {
            QSqlQuery attendanceQuery;
            attendanceQuery.prepare(R"(
                SELECT present FROM attendance
                WHERE student_id = :studentId AND subject_id = :subjectId AND date = :date
            )");
            attendanceQuery.bindValue(":studentId", studentId);
            attendanceQuery.bindValue(":subjectId", subjectId);
            attendanceQuery.bindValue(":date", currentDate.toString("yyyy-MM-dd"));

            QString status = "Nieobecny";
            if (attendanceQuery.exec() && attendanceQuery.next()) {
                bool present = attendanceQuery.value(0).toBool();
                status = present ? "Obecny" : "Nieobecny";
            }

            attendanceList.append({subjectName, currentDate, status});
            currentDate = currentDate.addDays(intervalDays);
        }
    }

    auto model = new QStandardItemModel(attendanceList.size(), 3, this);
    model->setHeaderData(0, Qt::Horizontal, "Przedmiot");
    model->setHeaderData(1, Qt::Horizontal, "Data");
    model->setHeaderData(2, Qt::Horizontal, "Status");

    for (int row = 0; row < attendanceList.size(); ++row) {
        model->setItem(row, 0, new QStandardItem(attendanceList[row].subjectName));
        model->setItem(row, 1, new QStandardItem(attendanceList[row].date.toString("dd.MM.yyyy")));
        model->setItem(row, 2, new QStandardItem(attendanceList[row].status));
    }

    ui->attendanceTableView->setModel(model);
    ui->attendanceTableView->resizeColumnsToContents();
}


