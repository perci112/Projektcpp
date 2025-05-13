/********************************************************************************
** Form generated from reading UI file 'employeewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEEWINDOW_H
#define UI_EMPLOYEEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_employeewindow
{
public:
    QComboBox *subjectComboBox;
    QLabel *label;
    QTableView *studentsTableView;
    QSpinBox *gradeSpinBox;
    QLabel *label_2;
    QPushButton *assignGradeButton;

    void setupUi(QDialog *employeewindow)
    {
        if (employeewindow->objectName().isEmpty())
            employeewindow->setObjectName("employeewindow");
        employeewindow->resize(678, 300);
        subjectComboBox = new QComboBox(employeewindow);
        subjectComboBox->setObjectName("subjectComboBox");
        subjectComboBox->setGeometry(QRect(90, 20, 131, 22));
        label = new QLabel(employeewindow);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 20, 61, 16));
        studentsTableView = new QTableView(employeewindow);
        studentsTableView->setObjectName("studentsTableView");
        studentsTableView->setGeometry(QRect(310, 10, 256, 192));
        gradeSpinBox = new QSpinBox(employeewindow);
        gradeSpinBox->setObjectName("gradeSpinBox");
        gradeSpinBox->setGeometry(QRect(141, 60, 51, 22));
        gradeSpinBox->setMinimum(2);
        gradeSpinBox->setMaximum(5);
        label_2 = new QLabel(employeewindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 60, 49, 16));
        assignGradeButton = new QPushButton(employeewindow);
        assignGradeButton->setObjectName("assignGradeButton");
        assignGradeButton->setGeometry(QRect(104, 120, 101, 24));

        retranslateUi(employeewindow);

        QMetaObject::connectSlotsByName(employeewindow);
    } // setupUi

    void retranslateUi(QDialog *employeewindow)
    {
        employeewindow->setWindowTitle(QCoreApplication::translate("employeewindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("employeewindow", "Przedmiot", nullptr));
        label_2->setText(QCoreApplication::translate("employeewindow", "Ocena", nullptr));
        assignGradeButton->setText(QCoreApplication::translate("employeewindow", "Zapisz ocene", nullptr));
    } // retranslateUi

};

namespace Ui {
    class employeewindow: public Ui_employeewindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEEWINDOW_H
