#ifndef EMPLOYEEWINDOW_H
#define EMPLOYEEWINDOW_H

#include <QDialog>
#include <QSqlQueryModel>
#include <QDate>

namespace Ui {
class employeewindow;
}

class employeewindow : public QDialog
{
    Q_OBJECT

public:
    explicit employeewindow(QString employeeId, QWidget *parent = nullptr);
    ~employeewindow();

private slots:
    void on_subjectComboBox_currentIndexChanged(int index);
    void on_assignGradeButton_clicked();
    void on_saveAttendanceButton_clicked();
    void on_saveScheduleButton_clicked();
    void on_calendarWidget_clicked(const QDate &date);
    void on_subject2ComboBox_currentIndexChanged(int index); // <--- dodaj to


private:
    void loadSubjects();
    void loadSubjectsToSecondComboBox();  // <-- DODAJ TO
    void loadStudentsForSubject(int subjectId);
    void loadAttendanceForSubject(int subjectId);
    void loadAttendanceList(const QList<QString> &students);
    QList<QString> getPresentStudents();
    bool isTodayScheduled(int subjectId);
    bool isClassDay(int subjectId, const QDate &date);
    void loadSchedule();


    Ui::employeewindow *ui;
    QString employeeId;
    QSqlQueryModel *studentModel;
};

#endif // EMPLOYEEWINDOW_H
