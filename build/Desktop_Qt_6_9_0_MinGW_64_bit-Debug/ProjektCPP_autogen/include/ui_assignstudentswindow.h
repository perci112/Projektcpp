/********************************************************************************
** Form generated from reading UI file 'assignstudentswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASSIGNSTUDENTSWINDOW_H
#define UI_ASSIGNSTUDENTSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_AssignStudentsWindow
{
public:
    QComboBox *comboBoxDirections;
    QPushButton *assignButton;
    QTableView *studentsTableView;

    void setupUi(QDialog *AssignStudentsWindow)
    {
        if (AssignStudentsWindow->objectName().isEmpty())
            AssignStudentsWindow->setObjectName("AssignStudentsWindow");
        AssignStudentsWindow->resize(507, 300);
        comboBoxDirections = new QComboBox(AssignStudentsWindow);
        comboBoxDirections->setObjectName("comboBoxDirections");
        comboBoxDirections->setGeometry(QRect(40, 20, 101, 22));
        assignButton = new QPushButton(AssignStudentsWindow);
        assignButton->setObjectName("assignButton");
        assignButton->setGeometry(QRect(50, 110, 75, 24));
        studentsTableView = new QTableView(AssignStudentsWindow);
        studentsTableView->setObjectName("studentsTableView");
        studentsTableView->setGeometry(QRect(200, 30, 256, 192));

        retranslateUi(AssignStudentsWindow);

        QMetaObject::connectSlotsByName(AssignStudentsWindow);
    } // setupUi

    void retranslateUi(QDialog *AssignStudentsWindow)
    {
        AssignStudentsWindow->setWindowTitle(QCoreApplication::translate("AssignStudentsWindow", "Dialog", nullptr));
        assignButton->setText(QCoreApplication::translate("AssignStudentsWindow", "Przypisz", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AssignStudentsWindow: public Ui_AssignStudentsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASSIGNSTUDENTSWINDOW_H
