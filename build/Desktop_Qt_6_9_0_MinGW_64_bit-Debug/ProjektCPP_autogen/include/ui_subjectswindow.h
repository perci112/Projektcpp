/********************************************************************************
** Form generated from reading UI file 'subjectswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBJECTSWINDOW_H
#define UI_SUBJECTSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_SubjectsWindow
{
public:
    QLineEdit *nameLineEdit;
    QLineEdit *descriptionLineEdit;
    QLabel *label;
    QLabel *label_2;
    QTableView *subjectsTableView;
    QPushButton *addSubjectButton;
    QPushButton *deleteSubjectButton;
    QComboBox *directionComboBox;
    QLabel *label_3;
    QComboBox *coordinatorComboBox;
    QLabel *label_4;

    void setupUi(QDialog *SubjectsWindow)
    {
        if (SubjectsWindow->objectName().isEmpty())
            SubjectsWindow->setObjectName("SubjectsWindow");
        SubjectsWindow->resize(851, 296);
        nameLineEdit = new QLineEdit(SubjectsWindow);
        nameLineEdit->setObjectName("nameLineEdit");
        nameLineEdit->setGeometry(QRect(130, 20, 113, 22));
        descriptionLineEdit = new QLineEdit(SubjectsWindow);
        descriptionLineEdit->setObjectName("descriptionLineEdit");
        descriptionLineEdit->setGeometry(QRect(130, 50, 113, 22));
        label = new QLabel(SubjectsWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 101, 16));
        label_2 = new QLabel(SubjectsWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 50, 101, 16));
        subjectsTableView = new QTableView(SubjectsWindow);
        subjectsTableView->setObjectName("subjectsTableView");
        subjectsTableView->setGeometry(QRect(420, 20, 256, 192));
        addSubjectButton = new QPushButton(SubjectsWindow);
        addSubjectButton->setObjectName("addSubjectButton");
        addSubjectButton->setGeometry(QRect(120, 140, 121, 24));
        deleteSubjectButton = new QPushButton(SubjectsWindow);
        deleteSubjectButton->setObjectName("deleteSubjectButton");
        deleteSubjectButton->setGeometry(QRect(120, 180, 121, 24));
        directionComboBox = new QComboBox(SubjectsWindow);
        directionComboBox->setObjectName("directionComboBox");
        directionComboBox->setGeometry(QRect(130, 80, 111, 22));
        label_3 = new QLabel(SubjectsWindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 80, 49, 16));
        coordinatorComboBox = new QComboBox(SubjectsWindow);
        coordinatorComboBox->setObjectName("coordinatorComboBox");
        coordinatorComboBox->setGeometry(QRect(130, 110, 111, 22));
        label_4 = new QLabel(SubjectsWindow);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(38, 110, 71, 20));

        retranslateUi(SubjectsWindow);

        QMetaObject::connectSlotsByName(SubjectsWindow);
    } // setupUi

    void retranslateUi(QDialog *SubjectsWindow)
    {
        SubjectsWindow->setWindowTitle(QCoreApplication::translate("SubjectsWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("SubjectsWindow", "Nazwa przedmiotu", nullptr));
        label_2->setText(QCoreApplication::translate("SubjectsWindow", "Opis przedmiotu", nullptr));
        addSubjectButton->setText(QCoreApplication::translate("SubjectsWindow", "Dodaj przedmiot", nullptr));
        deleteSubjectButton->setText(QCoreApplication::translate("SubjectsWindow", "Usu\305\204 przedmiot", nullptr));
        label_3->setText(QCoreApplication::translate("SubjectsWindow", "Kierunek", nullptr));
        label_4->setText(QCoreApplication::translate("SubjectsWindow", "Koordynator", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SubjectsWindow: public Ui_SubjectsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBJECTSWINDOW_H
