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
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_studentwindow
{
public:
    QLabel *firstNameLabel;
    QLabel *lastNameLabel;
    QLabel *emailLabel;

    void setupUi(QDialog *studentwindow)
    {
        if (studentwindow->objectName().isEmpty())
            studentwindow->setObjectName("studentwindow");
        studentwindow->resize(400, 300);
        firstNameLabel = new QLabel(studentwindow);
        firstNameLabel->setObjectName("firstNameLabel");
        firstNameLabel->setGeometry(QRect(80, 40, 49, 16));
        lastNameLabel = new QLabel(studentwindow);
        lastNameLabel->setObjectName("lastNameLabel");
        lastNameLabel->setGeometry(QRect(80, 80, 49, 16));
        emailLabel = new QLabel(studentwindow);
        emailLabel->setObjectName("emailLabel");
        emailLabel->setGeometry(QRect(90, 120, 49, 16));

        retranslateUi(studentwindow);

        QMetaObject::connectSlotsByName(studentwindow);
    } // setupUi

    void retranslateUi(QDialog *studentwindow)
    {
        studentwindow->setWindowTitle(QCoreApplication::translate("studentwindow", "Dialog", nullptr));
        firstNameLabel->setText(QCoreApplication::translate("studentwindow", "TextLabel", nullptr));
        lastNameLabel->setText(QCoreApplication::translate("studentwindow", "TextLabel", nullptr));
        emailLabel->setText(QCoreApplication::translate("studentwindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class studentwindow: public Ui_studentwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTWINDOW_H
