/********************************************************************************
** Form generated from reading UI file 'employeeswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEESWINDOW_H
#define UI_EMPLOYEESWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_EmployeesWindow
{
public:
    QPushButton *addEmployeeButton;
    QLineEdit *firstNameLineEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QTableView *employeesTableView;
    QLineEdit *lastNameLineEdit;
    QLineEdit *emailLineEdit;
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QPushButton *deleteEmployeeButton;

    void setupUi(QDialog *EmployeesWindow)
    {
        if (EmployeesWindow->objectName().isEmpty())
            EmployeesWindow->setObjectName("EmployeesWindow");
        EmployeesWindow->resize(648, 300);
        addEmployeeButton = new QPushButton(EmployeesWindow);
        addEmployeeButton->setObjectName("addEmployeeButton");
        addEmployeeButton->setGeometry(QRect(80, 170, 141, 24));
        firstNameLineEdit = new QLineEdit(EmployeesWindow);
        firstNameLineEdit->setObjectName("firstNameLineEdit");
        firstNameLineEdit->setGeometry(QRect(100, 20, 113, 22));
        label = new QLabel(EmployeesWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 20, 49, 16));
        label_2 = new QLabel(EmployeesWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 50, 61, 16));
        label_3 = new QLabel(EmployeesWindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 80, 49, 16));
        label_4 = new QLabel(EmployeesWindow);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 110, 49, 16));
        label_5 = new QLabel(EmployeesWindow);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 140, 49, 16));
        employeesTableView = new QTableView(EmployeesWindow);
        employeesTableView->setObjectName("employeesTableView");
        employeesTableView->setGeometry(QRect(250, 10, 256, 192));
        lastNameLineEdit = new QLineEdit(EmployeesWindow);
        lastNameLineEdit->setObjectName("lastNameLineEdit");
        lastNameLineEdit->setGeometry(QRect(100, 50, 113, 22));
        emailLineEdit = new QLineEdit(EmployeesWindow);
        emailLineEdit->setObjectName("emailLineEdit");
        emailLineEdit->setGeometry(QRect(100, 80, 113, 22));
        usernameLineEdit = new QLineEdit(EmployeesWindow);
        usernameLineEdit->setObjectName("usernameLineEdit");
        usernameLineEdit->setGeometry(QRect(100, 110, 111, 21));
        passwordLineEdit = new QLineEdit(EmployeesWindow);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setGeometry(QRect(100, 140, 113, 22));
        deleteEmployeeButton = new QPushButton(EmployeesWindow);
        deleteEmployeeButton->setObjectName("deleteEmployeeButton");
        deleteEmployeeButton->setGeometry(QRect(80, 200, 141, 24));

        retranslateUi(EmployeesWindow);

        QMetaObject::connectSlotsByName(EmployeesWindow);
    } // setupUi

    void retranslateUi(QDialog *EmployeesWindow)
    {
        EmployeesWindow->setWindowTitle(QCoreApplication::translate("EmployeesWindow", "Dialog", nullptr));
        addEmployeeButton->setText(QCoreApplication::translate("EmployeesWindow", "Dodaj pracownika", nullptr));
        label->setText(QCoreApplication::translate("EmployeesWindow", "Imie", nullptr));
        label_2->setText(QCoreApplication::translate("EmployeesWindow", "Nazwisko", nullptr));
        label_3->setText(QCoreApplication::translate("EmployeesWindow", "Email", nullptr));
        label_4->setText(QCoreApplication::translate("EmployeesWindow", "login", nullptr));
        label_5->setText(QCoreApplication::translate("EmployeesWindow", "has\305\202o", nullptr));
        deleteEmployeeButton->setText(QCoreApplication::translate("EmployeesWindow", "Usu\305\204 pracownika", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmployeesWindow: public Ui_EmployeesWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEESWINDOW_H
