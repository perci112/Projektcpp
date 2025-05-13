#ifndef EMPLOYEEWINDOW_H
#define EMPLOYEEWINDOW_H

#include <QDialog>
#include <QSqlQueryModel>

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

private:
    Ui::employeewindow *ui;
    QString employeeId;
    QSqlQueryModel *studentModel;

    void loadSubjects();
    void loadStudentsForSubject(int subjectId);
};

#endif // EMPLOYEEWINDOW_H
