#include "finddialog.h"
#include "ui_finddialog.h"
#include "QString"
#include "mainwindow.h"
#include "QTextEdit"

FindDialog::FindDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindDialog)
{
    ui->setupUi(this);
}

FindDialog::~FindDialog()
{
    delete ui;
}

void FindDialog::on_pushButton_2_clicked()
{
    this->close();
}

void FindDialog::on_pushButton_clicked()
{
    MainWindow win;
    win.searchText(ui->lineEdit->text());


}
