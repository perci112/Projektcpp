#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "adminwindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_loginButton_clicked();

private:
    Ui::MainWindow *ui;
    AdminWindow *adminWindow; // Dodaj to pole
};

#endif // MAINWINDOW_H
