#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "QtWidgets/QMainWindow"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_gitHubLink_clicked();
    void on_newScene_clicked();

private:
    Ui::MainWindow *ui;
    QString link="https://github.com/SemQ20?tab=repositories";
};
#endif // MAINWINDOW_H
