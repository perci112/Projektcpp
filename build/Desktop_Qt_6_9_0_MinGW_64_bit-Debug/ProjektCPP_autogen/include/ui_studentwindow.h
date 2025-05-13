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
        subjectsTableView->setGeometry(QRect(210, 220, 256, 192));
        attendanceTableView = new QTableView(studentwindow);
        attendanceTableView->setObjectName("attendanceTableView");
        attendanceTableView->setGeometry(QRect(210, 420, 256, 192));
        scholarshipLabel = new QLabel(studentwindow);
        scholarshipLabel->setObjectName("scholarshipLabel");
        scholarshipLabel->setGeometry(QRect(150, 240, 49, 16));
        averageGradeLabel = new QLabel(studentwindow);
        averageGradeLabel->setObjectName("averageGradeLabel");
        averageGradeLabel->setGeometry(QRect(150, 450, 49, 16));

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
    } // retranslateUi

};

namespace Ui {
    class studentwindow: public Ui_studentwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTWINDOW_H
