#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QColorDialog"
#include "QFileDialog"
#include "QFile"
#include "QTextStream"
#include "QFontDialog"
#include "QFont"
#include "QTextCharFormat"
#include "QInputDialog"
#include "QTextBlock"

#include "finddialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_new_triggered()
{
    ui->textEdit->clear();
}

void MainWindow::on_action_open_triggered()
{
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::AnyFile);
    QString filename = dialog.getOpenFileName(NULL,"Open file","","");
    QFile file(filename);
    file.open(QFile::ReadOnly|QFile::Text);
    QTextStream in(&file);
    ui->textEdit->setText(in.readAll());
    file.close();
}

void MainWindow::on_action_saveas_triggered()
{
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::AnyFile);
    QString filename = dialog.getSaveFileName(NULL,"Save file","","");
    QFile file(filename);
    file.open(QFile::WriteOnly|QFile::Text);
    QTextStream out(&file);
    out << ui->textEdit->toHtml();
    out.flush();
    file.close();
}

void MainWindow::on_action_undo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_action_copy_triggered()
{
    __copytext = ui->textEdit->textCursor().selectedText();
}

void MainWindow::on_action_paste_triggered()
{
    ui->textEdit->textCursor().insertHtml(__copytext);
}

void MainWindow::on_action_font_triggered()
{
    QFontDialog dialog;
    QFont font = dialog.getFont(NULL);
    QTextCharFormat format;
    format.setFont(font);
    ui->textEdit->textCursor().setCharFormat(format);
}

void MainWindow::on_action_alignLeft_triggered()
{
    ui->textEdit->setAlignment(Qt::AlignLeft);
}

void MainWindow::on_action_alignCenter_triggered()
{
    ui->textEdit->setAlignment(Qt::AlignCenter);
}

void MainWindow::on_action_alignRight_triggered()
{
    ui->textEdit->setAlignment(Qt::AlignRight);
}

void MainWindow::on_action_search_triggered()
{
    bool bOk;
    QString str = QInputDialog::getText(0,"Найти","Введите текст:",QLineEdit::Normal,"",&bOk);
    if (!bOk) { return; }
    QTextCursor oldCursor = ui->textEdit->textCursor();
    ui->textEdit->setTextCursor(QTextCursor(ui->textEdit->document()->findBlockByLineNumber(0)));
    bool finded = ui->textEdit->find(str);
    if (!finded) {
        ui->textEdit->setTextCursor(oldCursor);
    }


}

void MainWindow::on_action_gotoStr_triggered()
{
    bool ok;
    int num = QInputDialog::getInt(0, "Перейти", "На строку:", 1, 1, ui->textEdit->document()->lineCount(),1,&ok); // целое значение запрашивает, 1 по умолч, 1 мин знач, макс зн-ие. 1,
    QTextBlock block = ui->textEdit->document()->findBlockByLineNumber(num-1); //
    QTextCursor cursor(block);
    ui->textEdit->setTextCursor(cursor);
}
