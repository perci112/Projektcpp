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
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTimeEdit>

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
    QListWidget *attendanceListWidget;
    QPushButton *saveAttendanceButton;
    QDateEdit *dateEditAttendance;
    QComboBox *subject2ComboBox;
    QComboBox *weekdayComboBox;
    QCheckBox *everyTwoWeeksCheckBox;
    QDateEdit *dateEdit;
    QPushButton *saveScheduleButton;
    QCalendarWidget *calendarWidget;
    QListWidget *listWidget;
    QTimeEdit *startTimeEdit;
    QTimeEdit *endTimeEdit;

    void setupUi(QDialog *employeewindow)
    {
        if (employeewindow->objectName().isEmpty())
            employeewindow->setObjectName("employeewindow");
        employeewindow->resize(1176, 648);
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
        attendanceListWidget = new QListWidget(employeewindow);
        attendanceListWidget->setObjectName("attendanceListWidget");
        attendanceListWidget->setGeometry(QRect(310, 210, 256, 192));
        saveAttendanceButton = new QPushButton(employeewindow);
        saveAttendanceButton->setObjectName("saveAttendanceButton");
        saveAttendanceButton->setGeometry(QRect(160, 210, 121, 24));
        dateEditAttendance = new QDateEdit(employeewindow);
        dateEditAttendance->setObjectName("dateEditAttendance");
        dateEditAttendance->setEnabled(false);
        dateEditAttendance->setGeometry(QRect(160, 240, 110, 22));
        subject2ComboBox = new QComboBox(employeewindow);
        subject2ComboBox->setObjectName("subject2ComboBox");
        subject2ComboBox->setGeometry(QRect(110, 420, 101, 22));
        weekdayComboBox = new QComboBox(employeewindow);
        weekdayComboBox->setObjectName("weekdayComboBox");
        weekdayComboBox->setGeometry(QRect(110, 450, 101, 22));
        everyTwoWeeksCheckBox = new QCheckBox(employeewindow);
        everyTwoWeeksCheckBox->setObjectName("everyTwoWeeksCheckBox");
        everyTwoWeeksCheckBox->setGeometry(QRect(110, 480, 101, 20));
        dateEdit = new QDateEdit(employeewindow);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(100, 510, 110, 22));
        saveScheduleButton = new QPushButton(employeewindow);
        saveScheduleButton->setObjectName("saveScheduleButton");
        saveScheduleButton->setGeometry(QRect(90, 540, 131, 24));
        calendarWidget = new QCalendarWidget(employeewindow);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setGeometry(QRect(310, 420, 304, 190));
        listWidget = new QListWidget(employeewindow);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(570, 210, 256, 192));
        startTimeEdit = new QTimeEdit(employeewindow);
        startTimeEdit->setObjectName("startTimeEdit");
        startTimeEdit->setGeometry(QRect(100, 570, 118, 22));
        endTimeEdit = new QTimeEdit(employeewindow);
        endTimeEdit->setObjectName("endTimeEdit");
        endTimeEdit->setGeometry(QRect(100, 590, 118, 22));

        retranslateUi(employeewindow);

        QMetaObject::connectSlotsByName(employeewindow);
    } // setupUi

    void retranslateUi(QDialog *employeewindow)
    {
        employeewindow->setWindowTitle(QCoreApplication::translate("employeewindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("employeewindow", "Przedmiot", nullptr));
        label_2->setText(QCoreApplication::translate("employeewindow", "Ocena", nullptr));
        assignGradeButton->setText(QCoreApplication::translate("employeewindow", "Zapisz ocene", nullptr));
        saveAttendanceButton->setText(QCoreApplication::translate("employeewindow", "Zapisz frekwencj\304\231", nullptr));
        everyTwoWeeksCheckBox->setText(QCoreApplication::translate("employeewindow", "Co 2 tygodnie?", nullptr));
        saveScheduleButton->setText(QCoreApplication::translate("employeewindow", "Zapisz harmonogram", nullptr));
    } // retranslateUi

};

namespace Ui {
    class employeewindow: public Ui_employeewindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEEWINDOW_H
