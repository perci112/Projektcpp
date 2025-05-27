#include "employeewindow.h"
#include "ui_employeewindow.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QDebug>
#include <QDate>
#include <QTextCharFormat>
#include <QListWidgetItem>

employeewindow::employeewindow(QString employeeId, QWidget *parent)
    : QDialog(parent),
    ui(new Ui::employeewindow),
    employeeId(std::move(employeeId)),
    studentModel(new QSqlQueryModel(this))
{
    ui->setupUi(this);

    // Konfiguracja kontrolek
    ui->gradeSpinBox->setRange(2, 5);
    ui->dateEditAttendance->setDate(QDate::currentDate());

    loadSubjects();
    connect(ui->subjectComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &employeewindow::loadSchedule);
    loadSchedule();
    loadSubjectsToSecondComboBox();

    qDebug() << "employeeId:" << this->employeeId;

    connect(ui->dateEditAttendance, &QDateEdit::dateChanged, this, [this](const QDate &) {
        int subjectId = ui->subjectComboBox->currentData().toInt();
        loadAttendanceForSubject(subjectId);
    });
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

    if (ui->subjectComboBox->count() > 0) {
        int subjectId = ui->subjectComboBox->currentData().toInt();
        loadStudentsForSubject(subjectId);
        loadAttendanceForSubject(subjectId);
    }
}

void employeewindow::loadSubjectsToSecondComboBox()
{
    QSqlQuery query;
    query.prepare("SELECT id, name FROM subjects WHERE coordinator_id = :id");
    query.bindValue(":id", employeeId);

    if (!query.exec()) {
        QMessageBox::critical(this, "Błąd", "Nie udało się załadować przedmiotów: " + query.lastError().text());
        return;
    }

    ui->subject2ComboBox->clear();
    while (query.next()) {
        ui->subject2ComboBox->addItem(query.value("name").toString(), query.value("id").toInt());
    }
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
        ORDER BY users.last_name, users.first_name
    )");
    query.bindValue(":subjectId", subjectId);

    if (!query.exec()) {
        QMessageBox::critical(this, "Błąd", "Nie udało się pobrać studentów: " + query.lastError().text());
        return;
    }

    // Używamy std::move, żeby uniknąć ostrzeżenia deprecacji
    studentModel->setQuery(std::move(query));

    studentModel->setHeaderData(1, Qt::Horizontal, "Student");
    studentModel->setHeaderData(2, Qt::Horizontal, "Ocena");

    ui->studentsTableView->setModel(studentModel);
    ui->studentsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->studentsTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->studentsTableView->hideColumn(0);
}

void employeewindow::loadAttendanceForSubject(int subjectId)
{
    ui->attendanceListWidget->clear();
    QDate selectedDate = ui->dateEditAttendance->date();

    QSqlQuery studentsQuery;
    studentsQuery.prepare(R"(
        SELECT users.id, users.first_name || ' ' || users.last_name AS full_name
        FROM users
        JOIN student_subjects ON users.id = student_subjects.student_id
        WHERE student_subjects.subject_id = :subjectId
        ORDER BY users.last_name, users.first_name
    )");
    studentsQuery.bindValue(":subjectId", subjectId);

    if (!studentsQuery.exec()) {
        QMessageBox::critical(this, "Błąd", "Nie udało się pobrać studentów: " + studentsQuery.lastError().text());
        return;
    }

    QSqlQuery attendanceQuery;
    attendanceQuery.prepare(R"(
        SELECT student_id, present
        FROM attendance
        WHERE subject_id = :subjectId AND date = :date
    )");
    attendanceQuery.bindValue(":subjectId", subjectId);
    attendanceQuery.bindValue(":date", selectedDate.toString("yyyy-MM-dd"));

    if (!attendanceQuery.exec()) {
        QMessageBox::critical(this, "Błąd", "Nie udało się pobrać frekwencji: " + attendanceQuery.lastError().text());
        return;
    }

    QMap<int, bool> attendanceMap;
    while (attendanceQuery.next()) {
        attendanceMap[attendanceQuery.value(0).toInt()] = attendanceQuery.value(1).toBool();
    }

    while (studentsQuery.next()) {
        int studentId = studentsQuery.value(0).toInt();
        QString fullName = studentsQuery.value(1).toString();

        QListWidgetItem *item = new QListWidgetItem(fullName);
        item->setData(Qt::UserRole, studentId);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(attendanceMap.value(studentId, false) ? Qt::Checked : Qt::Unchecked);

        ui->attendanceListWidget->addItem(item);
    }
}

void employeewindow::on_subjectComboBox_currentIndexChanged(int /*index*/)
{
    int subjectId = ui->subjectComboBox->currentData().toInt();
    loadStudentsForSubject(subjectId);
    loadAttendanceForSubject(subjectId);
}

void employeewindow::on_subject2ComboBox_currentIndexChanged(int /*index*/)
{
    // Przykładowa implementacja, w razie potrzeby można rozbudować
    int subjectId = ui->subject2ComboBox->currentData().toInt();
    qDebug() << "Wybrano w drugim ComboBoxie subjectId:" << subjectId;
}

void employeewindow::on_calendarWidget_clicked(const QDate &date)
{
    // Przykładowa implementacja: po kliknięciu w kalendarz, ustawiamy dateEditAttendance na wybraną datę
    ui->dateEditAttendance->setDate(date);
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
    query.bindValue(":date", QDate::currentDate().toString("yyyy-MM-dd"));

    if (!query.exec()) {
        QMessageBox::critical(this, "Błąd", "Nie udało się przypisać oceny: " + query.lastError().text());
    } else {
        QMessageBox::information(this, "Sukces", "Ocena została przypisana.");
        loadStudentsForSubject(subjectId); // Odśwież listę z ocenami
    }
}

void employeewindow::on_saveAttendanceButton_clicked()
{
    int subjectId = ui->subjectComboBox->currentData().toInt();
    QDate selectedDate = ui->dateEditAttendance->date();

    if (!isClassDay(subjectId, selectedDate)) {
        QMessageBox::warning(this, "Błąd", "Nie można zapisać frekwencji, bo tego dnia nie ma zajęć.");
        return;
    }

    // Usunięcie istniejących wpisów frekwencji dla tego dnia i przedmiotu
    QSqlQuery delQuery;
    delQuery.prepare("DELETE FROM attendance WHERE subject_id = :subjectId AND date = :date");
    delQuery.bindValue(":subjectId", subjectId);
    delQuery.bindValue(":date", selectedDate.toString("yyyy-MM-dd"));

    if (!delQuery.exec()) {
        QMessageBox::warning(this, "Błąd", "Nie udało się wyczyścić starej frekwencji: " + delQuery.lastError().text());
        return;
    }

    // Wstawienie wpisów dla wszystkich studentów, z wartością present ustawioną na 1 lub 0
    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO attendance (student_id, subject_id, date, present) VALUES (:studentId, :subjectId, :date, :present)");

    for (int i = 0; i < ui->attendanceListWidget->count(); ++i) {
        QListWidgetItem *item = ui->attendanceListWidget->item(i);
        int studentId = item->data(Qt::UserRole).toInt();
        bool present = (item->checkState() == Qt::Checked);

        insertQuery.bindValue(":studentId", studentId);
        insertQuery.bindValue(":subjectId", subjectId);
        insertQuery.bindValue(":date", selectedDate.toString("yyyy-MM-dd"));
        insertQuery.bindValue(":present", present ? 1 : 0);

        if (!insertQuery.exec()) {
            QMessageBox::warning(this, "Błąd", "Nie udało się zapisać frekwencji: " + insertQuery.lastError().text());
            return;
        }
    }

    QMessageBox::information(this, "Sukces", "Frekwencja została zapisana.");
}


bool employeewindow::isClassDay(int subjectId, const QDate &date)
{
    int dayOfWeek = date.dayOfWeek(); // 1 = Monday ... 7 = Sunday

    QSqlQuery query;
    query.prepare(R"(
        SELECT COUNT(*)
        FROM schedule
        WHERE subject_id = :subjectId
          AND weekday = :dow
          AND start_date <= :date
          -- tutaj możesz też rozważyć datę końcową zajęć, jeśli masz taką w tabeli
    )");
    query.bindValue(":subjectId", subjectId);
    query.bindValue(":dow", dayOfWeek);
    query.bindValue(":date", date.toString("yyyy-MM-dd"));

    if (!query.exec()) {
        qDebug() << "Błąd sprawdzania dnia zajęć:" << query.lastError().text();
        return false;
    }

    if (query.next()) {
        return query.value(0).toInt() > 0;
    }

    return false;
}

void employeewindow::on_saveScheduleButton_clicked()
{
    QString subjectName = ui->subjectComboBox->currentText();
    bool everyTwoWeeks = ui->everyTwoWeeksCheckBox->isChecked();
    QDate startDate = ui->dateEdit->date();
    QString startTime = ui->startTimeEdit->time().toString("HH:mm");
    QString endTime = ui->endTimeEdit->time().toString("HH:mm");

    if (subjectName.isEmpty()) return;

    int interval = everyTwoWeeks ? 14 : 7;
    QDate currentDate = startDate;
    QDate endDate = startDate.addMonths(3);

    QTextCharFormat format;
    format.setBackground(Qt::yellow);
    format.setToolTip(subjectName);
    ui->listWidget->clear();

    QSqlQuery delQuery;
    delQuery.prepare("DELETE FROM schedule WHERE subject_id = (SELECT id FROM subjects WHERE name = :subject)");
    delQuery.bindValue(":subject", subjectName);

    if (!delQuery.exec()) {
        QMessageBox::warning(this, "Błąd", "Nie udało się usunąć starego harmonogramu: " + delQuery.lastError().text());
        return;
    }

    QSqlQuery insertQuery;
    insertQuery.prepare(R"(
        INSERT INTO schedule (subject_id, weekday, every_two_weeks, start_date, start_time, end_time)
        VALUES ((SELECT id FROM subjects WHERE name = :subject), :weekday, :everyTwoWeeks, :startDate, :startTime, :endTime)
    )");

    while (currentDate <= endDate) {
        ui->calendarWidget->setDateTextFormat(currentDate, format);
        ui->listWidget->addItem(currentDate.toString("dd.MM.yyyy") + " - " + subjectName + " (godz. " + startTime + " - " + endTime + ")");

        insertQuery.bindValue(":subject", subjectName);
        insertQuery.bindValue(":weekday", currentDate.dayOfWeek());
        insertQuery.bindValue(":everyTwoWeeks", everyTwoWeeks);
        insertQuery.bindValue(":startDate", currentDate.toString("yyyy-MM-dd"));
        insertQuery.bindValue(":startTime", startTime);
        insertQuery.bindValue(":endTime", endTime);

        if (!insertQuery.exec()) {
            QMessageBox::warning(this, "Błąd", "Nie udało się zapisać harmonogramu: " + insertQuery.lastError().text());
            return;
        }

        currentDate = currentDate.addDays(interval);
    }
}
void employeewindow::loadSchedule()
{
    ui->listWidget->clear();
    ui->calendarWidget->setDateTextFormat(QDate(), QTextCharFormat()); // reset formatów

    QString subjectName = ui->subjectComboBox->currentText();
    if (subjectName.isEmpty())
        return;

    QSqlQuery query;
    query.prepare(R"(
        SELECT weekday, every_two_weeks, start_date, start_time, end_time
        FROM schedule
        WHERE subject_id = (SELECT id FROM subjects WHERE name = :subject)
    )");
    query.bindValue(":subject", subjectName);

    if (!query.exec()) {
        QMessageBox::warning(this, "Błąd", "Nie udało się załadować harmonogramu: " + query.lastError().text());
        return;
    }

    QTextCharFormat format;
    format.setBackground(Qt::yellow);
    format.setToolTip(subjectName);

    while (query.next()) {
        int weekday = query.value("weekday").toInt();
        bool everyTwoWeeks = query.value("every_two_weeks").toBool();
        QDate startDate = QDate::fromString(query.value("start_date").toString(), "yyyy-MM-dd");
        QString startTime = query.value("start_time").toString();
        QString endTime = query.value("end_time").toString();

        // Wyświetl wpis w listWidget
        ui->listWidget->addItem(startDate.toString("dd.MM.yyyy") + " - " + subjectName + " (godz. " + startTime + " - " + endTime + ")");

        // Podświetl dni w kalendarzu — dla uproszczenia podświetlimy dni od startDate co tydzień lub co 2 tygodnie
        int interval = everyTwoWeeks ? 14 : 7;
        QDate currentDate = startDate;
        QDate endDate = startDate.addMonths(3);

        while (currentDate <= endDate) {
            if (currentDate.dayOfWeek() == weekday) {
                ui->calendarWidget->setDateTextFormat(currentDate, format);
            }
            currentDate = currentDate.addDays(1);
        }
    }
}
