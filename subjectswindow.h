#ifndef SUBJECTSWINDOW_H
#define SUBJECTSWINDOW_H

#include <QDialog>
#include <QSqlTableModel>

namespace Ui {
class SubjectsWindow;
}

class SubjectsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SubjectsWindow(QWidget *parent = nullptr);
    ~SubjectsWindow();

private slots:
    void on_addSubjectButton_clicked();
    void loadCoordinators();
    void on_deleteSubjectButton_clicked();

private:
    Ui::SubjectsWindow *ui;
    QSqlTableModel *subjectModel;
    void loadSubjects();
    void loadDirections();

};

#endif // SUBJECTSWINDOW_H
