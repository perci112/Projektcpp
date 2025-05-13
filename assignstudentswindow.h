#ifndef ASSIGNSTUDENTSWINDOW_H
#define ASSIGNSTUDENTSWINDOW_H

#include <QDialog>
#include <QComboBox>

namespace Ui {
class AssignStudentsWindow;
}

class AssignStudentsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AssignStudentsWindow(QWidget *parent = nullptr);
    ~AssignStudentsWindow();

private slots:
    void on_assignButton_clicked();

private:
    Ui::AssignStudentsWindow *ui;
    void loadStudents();
    void loadDirections();
};

#endif // ASSIGNSTUDENTSWINDOW_H
