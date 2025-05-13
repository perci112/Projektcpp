/********************************************************************************
** Form generated from reading UI file 'studentswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTSWINDOW_H
#define UI_STUDENTSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_studentswindow
{
public:
    QLineEdit *lineEdit;
    QLabel *label;

    void setupUi(QDialog *studentswindow)
    {
        if (studentswindow->objectName().isEmpty())
            studentswindow->setObjectName("studentswindow");
        studentswindow->resize(400, 300);
        lineEdit = new QLineEdit(studentswindow);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(70, 20, 113, 22));
        label = new QLabel(studentswindow);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 20, 49, 16));

        retranslateUi(studentswindow);

        QMetaObject::connectSlotsByName(studentswindow);
    } // setupUi

    void retranslateUi(QDialog *studentswindow)
    {
        studentswindow->setWindowTitle(QCoreApplication::translate("studentswindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("studentswindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class studentswindow: public Ui_studentswindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTSWINDOW_H
