#ifndef STUDENTSWINDOW_H
#define STUDENTSWINDOW_H

#include <QDialog>

namespace Ui {
class studentswindow;
}

class studentswindow : public QDialog
{
    Q_OBJECT

public:
    explicit studentswindow(QWidget *parent = nullptr);
    ~studentswindow();

private:
    Ui::studentswindow *ui;
};

#endif // STUDENTSWINDOW_H
