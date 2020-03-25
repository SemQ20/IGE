
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "QtCore/QUrl"
#include "QtGUI/QDesktopServices"
#include "glmainwindow.h"
#include "guiige.h"
#include "scene.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);
}


MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_gitHubLink_clicked(){
    QDesktopServices::openUrl(QUrl(link));
}

void MainWindow::on_newScene_clicked(){
    GLWindow glMWind;
    IGE::Scene::createScene(glMWind,1280,720,"Window",NULL,NULL); 
}
