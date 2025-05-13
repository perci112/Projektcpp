#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adminwindow.h"
#include "employeewindow.h"

#include "studentwindow.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Inicjalizacja połączenia z bazą danych SQLite
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("sms.db");  // lokalny plik bazy danych

    if (!db.open()) {
        QMessageBox::critical(this, "Błąd bazy danych", db.lastError().text());
    } else {
        qDebug() << "Połączenie z bazą danych SQLite udane!";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // Przycisk testowy – np. do debugowania
}

void MainWindow::on_loginButton_clicked()
{
    QString username = ui->usernameLineEdit->text();  // Użycie wartości z pola tekstowego
    QString password = ui->passwordLineEdit->text();

    QSqlQuery query;
    query.prepare("SELECT role FROM users WHERE username = ? AND password = ?");
    query.addBindValue(username);
    query.addBindValue(password);

    if (!query.exec()) {
        QMessageBox::critical(this, "Błąd logowania", "Błąd zapytania: " + query.lastError().text());
        return;
    }

    if (query.next()) {
        QString role = query.value(0).toString();
        QMessageBox::information(this, "Sukces", "Zalogowano jako: " + role);

        if (role == "admin") {
            AdminWindow *adminWin = new AdminWindow(this);
            adminWin->setAttribute(Qt::WA_DeleteOnClose); // automatyczne usuwanie po zamknięciu
            adminWin->show();
        }else if (role == "student") {
            studentwindow *studentWin = new studentwindow(username, this);
            studentWin->setAttribute(Qt::WA_DeleteOnClose);
            studentWin->show();
        }
        else if (role == "employee") {
            // Pobieranie ID pracownika (users.id) po loginie
            QSqlQuery idQuery;
            idQuery.prepare("SELECT id FROM users WHERE username = ?");
            idQuery.addBindValue(username);
            if (idQuery.exec() && idQuery.next()) {
                QString employeeId = idQuery.value(0).toString();
                employeewindow *employeeWin = new employeewindow(employeeId, nullptr);

                employeeWin->setAttribute(Qt::WA_DeleteOnClose);
                employeeWin->show();
                this->close();
            }else {
                QMessageBox::critical(this, "Błąd", "Nie znaleziono ID pracownika.");
            }
        }
    } else {
        QMessageBox::warning(this, "Błąd logowania", "Nieprawidłowy login lub hasło.");
    }
}
