#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void on_action_new_triggered();

    void on_action_open_triggered();

    void on_action_saveas_triggered();

    void on_action_undo_triggered();

    void on_action_copy_triggered();

    void on_action_paste_triggered();

    void on_action_font_triggered();

    void on_action_alignLeft_triggered();

    void on_action_alignCenter_triggered();

    void on_action_alignRight_triggered();

    void on_action_search_triggered();

    void on_action_gotoStr_triggered();

private:
    Ui::MainWindow *ui;
    QString __copytext;
};

#endif // MAINWINDOW_H
