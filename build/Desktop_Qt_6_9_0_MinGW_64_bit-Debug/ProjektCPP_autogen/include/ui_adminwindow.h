/********************************************************************************
** Form generated from reading UI file 'adminwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWINDOW_H
#define UI_ADMINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_Admin
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *addStudentButton;
    QLineEdit *firstNameLineEdit;
    QLineEdit *lastNameLineEdit;
    QLineEdit *emailLineEdit;
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QTableView *studentsTableView;
    QPushButton *addStudentButton_2;
    QPushButton *saveChanges;
    QLineEdit *searchLineEdit;
    QLabel *label_6;
    QPushButton *searchButton;
    QPushButton *resetButton;
    QPushButton *manageSubjectsButton;
    QPushButton *manageEmployeesButton;
    QPushButton *pushButton;

    void setupUi(QDialog *Admin)
    {
        if (Admin->objectName().isEmpty())
            Admin->setObjectName("Admin");
        Admin->resize(833, 497);
        label = new QLabel(Admin);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 30, 49, 16));
        label_2 = new QLabel(Admin);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 60, 49, 16));
        label_3 = new QLabel(Admin);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 100, 49, 16));
        label_4 = new QLabel(Admin);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 140, 49, 16));
        label_5 = new QLabel(Admin);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 190, 49, 16));
        addStudentButton = new QPushButton(Admin);
        addStudentButton->setObjectName("addStudentButton");
        addStudentButton->setGeometry(QRect(70, 230, 121, 24));
        firstNameLineEdit = new QLineEdit(Admin);
        firstNameLineEdit->setObjectName("firstNameLineEdit");
        firstNameLineEdit->setGeometry(QRect(90, 30, 113, 22));
        lastNameLineEdit = new QLineEdit(Admin);
        lastNameLineEdit->setObjectName("lastNameLineEdit");
        lastNameLineEdit->setGeometry(QRect(90, 60, 113, 22));
        emailLineEdit = new QLineEdit(Admin);
        emailLineEdit->setObjectName("emailLineEdit");
        emailLineEdit->setGeometry(QRect(90, 100, 113, 22));
        usernameLineEdit = new QLineEdit(Admin);
        usernameLineEdit->setObjectName("usernameLineEdit");
        usernameLineEdit->setGeometry(QRect(90, 140, 113, 22));
        passwordLineEdit = new QLineEdit(Admin);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setGeometry(QRect(90, 180, 113, 22));
        studentsTableView = new QTableView(Admin);
        studentsTableView->setObjectName("studentsTableView");
        studentsTableView->setGeometry(QRect(540, 20, 256, 192));
        addStudentButton_2 = new QPushButton(Admin);
        addStudentButton_2->setObjectName("addStudentButton_2");
        addStudentButton_2->setGeometry(QRect(70, 270, 121, 24));
        saveChanges = new QPushButton(Admin);
        saveChanges->setObjectName("saveChanges");
        saveChanges->setGeometry(QRect(610, 230, 121, 24));
        searchLineEdit = new QLineEdit(Admin);
        searchLineEdit->setObjectName("searchLineEdit");
        searchLineEdit->setGeometry(QRect(330, 40, 113, 22));
        label_6 = new QLabel(Admin);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(258, 40, 61, 20));
        searchButton = new QPushButton(Admin);
        searchButton->setObjectName("searchButton");
        searchButton->setGeometry(QRect(340, 70, 75, 24));
        resetButton = new QPushButton(Admin);
        resetButton->setObjectName("resetButton");
        resetButton->setGeometry(QRect(340, 110, 111, 24));
        manageSubjectsButton = new QPushButton(Admin);
        manageSubjectsButton->setObjectName("manageSubjectsButton");
        manageSubjectsButton->setGeometry(QRect(70, 310, 141, 24));
        manageEmployeesButton = new QPushButton(Admin);
        manageEmployeesButton->setObjectName("manageEmployeesButton");
        manageEmployeesButton->setGeometry(QRect(340, 310, 81, 24));
        pushButton = new QPushButton(Admin);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(260, 230, 191, 24));

        retranslateUi(Admin);

        QMetaObject::connectSlotsByName(Admin);
    } // setupUi

    void retranslateUi(QDialog *Admin)
    {
        Admin->setWindowTitle(QCoreApplication::translate("Admin", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Admin", "Imie", nullptr));
        label_2->setText(QCoreApplication::translate("Admin", "Nazwisko", nullptr));
        label_3->setText(QCoreApplication::translate("Admin", "Email", nullptr));
        label_4->setText(QCoreApplication::translate("Admin", "Login", nullptr));
        label_5->setText(QCoreApplication::translate("Admin", "Has\305\202o", nullptr));
        addStudentButton->setText(QCoreApplication::translate("Admin", "Dodaj studenta", nullptr));
        addStudentButton_2->setText(QCoreApplication::translate("Admin", "Usu\305\204 studenta", nullptr));
        saveChanges->setText(QCoreApplication::translate("Admin", "Zapisz zmiany", nullptr));
        label_6->setText(QCoreApplication::translate("Admin", "Wyszukaj", nullptr));
        searchButton->setText(QCoreApplication::translate("Admin", "Szukaj", nullptr));
        resetButton->setText(QCoreApplication::translate("Admin", "Poka\305\274 wszystko", nullptr));
        manageSubjectsButton->setText(QCoreApplication::translate("Admin", "Poka\305\274 przedmoty", nullptr));
        manageEmployeesButton->setText(QCoreApplication::translate("Admin", "Pracownicy", nullptr));
        pushButton->setText(QCoreApplication::translate("Admin", "Przypisz kierunek do studenta", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Admin: public Ui_Admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
