#include "studentswindow.h"
#include "ui_studentswindow.h"

studentswindow::studentswindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::studentswindow)
{
    ui->setupUi(this);
}

studentswindow::~studentswindow()
{
    delete ui;
}
