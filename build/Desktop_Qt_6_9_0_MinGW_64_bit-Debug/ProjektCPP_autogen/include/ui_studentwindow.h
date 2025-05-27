/********************************************************************************
** Form generated from reading UI file 'studentwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTWINDOW_H
#define UI_STUDENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_studentwindow
{
public:
    QLabel *firstNameLabel;
    QLabel *lastNameLabel;
    QLabel *emailLabel;
    QTableView *gradesTableView;
    QTableView *subjectsTableView;
    QTableView *attendanceTableView;
    QLabel *scholarshipLabel;
    QLabel *averageGradeLabel;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *averageLabel;
    QLabel *label_4;
    QPushButton *pushButton;
    QLabel *stipendLabel;

    void setupUi(QDialog *studentwindow)
    {
        if (studentwindow->objectName().isEmpty())
            studentwindow->setObjectName("studentwindow");
        studentwindow->resize(531, 639);
        firstNameLabel = new QLabel(studentwindow);
        firstNameLabel->setObjectName("firstNameLabel");
        firstNameLabel->setGeometry(QRect(80, 40, 49, 16));
        lastNameLabel = new QLabel(studentwindow);
        lastNameLabel->setObjectName("lastNameLabel");
        lastNameLabel->setGeometry(QRect(80, 80, 49, 16));
        emailLabel = new QLabel(studentwindow);
        emailLabel->setObjectName("emailLabel");
        emailLabel->setGeometry(QRect(80, 120, 49, 16));
        gradesTableView = new QTableView(studentwindow);
        gradesTableView->setObjectName("gradesTableView");
        gradesTableView->setGeometry(QRect(210, 20, 256, 192));
        subjectsTableView = new QTableView(studentwindow);
        subjectsTableView->setObjectName("subjectsTableView");
        subjectsTableView->setGeometry(QRect(270, 430, 256, 192));
        attendanceTableView = new QTableView(studentwindow);
        attendanceTableView->setObjectName("attendanceTableView");
        attendanceTableView->setGeometry(QRect(10, 430, 256, 192));
        scholarshipLabel = new QLabel(studentwindow);
        scholarshipLabel->setObjectName("scholarshipLabel");
        scholarshipLabel->setGeometry(QRect(270, 410, 49, 16));
        averageGradeLabel = new QLabel(studentwindow);
        averageGradeLabel->setObjectName("averageGradeLabel");
        averageGradeLabel->setGeometry(QRect(10, 400, 49, 16));
        label = new QLabel(studentwindow);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 40, 49, 16));
        label_2 = new QLabel(studentwindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(8, 80, 61, 20));
        label_3 = new QLabel(studentwindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 120, 49, 21));
        averageLabel = new QLabel(studentwindow);
        averageLabel->setObjectName("averageLabel");
        averageLabel->setGeometry(QRect(80, 160, 121, 16));
        label_4 = new QLabel(studentwindow);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 160, 49, 16));
        pushButton = new QPushButton(studentwindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(40, 210, 121, 24));
        stipendLabel = new QLabel(studentwindow);
        stipendLabel->setObjectName("stipendLabel");
        stipendLabel->setGeometry(QRect(190, 230, 321, 16));

        retranslateUi(studentwindow);

        QMetaObject::connectSlotsByName(studentwindow);
    } // setupUi

    void retranslateUi(QDialog *studentwindow)
    {
        studentwindow->setWindowTitle(QCoreApplication::translate("studentwindow", "Dialog", nullptr));
        firstNameLabel->setText(QCoreApplication::translate("studentwindow", "TextLabel", nullptr));
        lastNameLabel->setText(QCoreApplication::translate("studentwindow", "TextLabel", nullptr));
        emailLabel->setText(QCoreApplication::translate("studentwindow", "TextLabel", nullptr));
        scholarshipLabel->setText(QCoreApplication::translate("studentwindow", "TextLabel", nullptr));
        averageGradeLabel->setText(QCoreApplication::translate("studentwindow", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("studentwindow", "Imie:", nullptr));
        label_2->setText(QCoreApplication::translate("studentwindow", "Nazwisko:", nullptr));
        label_3->setText(QCoreApplication::translate("studentwindow", "Mail:", nullptr));
        averageLabel->setText(QCoreApplication::translate("studentwindow", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("studentwindow", "\305\232rednia:", nullptr));
        pushButton->setText(QCoreApplication::translate("studentwindow", "Eksportuj do CSV", nullptr));
        stipendLabel->setText(QCoreApplication::translate("studentwindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class studentwindow: public Ui_studentwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTWINDOW_H
