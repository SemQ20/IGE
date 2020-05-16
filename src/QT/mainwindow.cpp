
#include "ui_mainwindow.h"

#if defined(VK_USE_PLATFORM_XLIB_KHR) || defined(VK_USE_PLATFORM_XCB_KHR)
#include <X11/Xutil.h>
#elif defined(VK_USE_PLATFORM_WAYLAND_KHR)
#include <linux/input.h>
#endif
#define VULKAN_HPP_NO_SMART_HANDLE
#define VULKAN_HPP_NO_EXCEPTIONS
#define VULKAN_HPP_TYPESAFE_CONVERSION
#include "../vulkan/vulkan.hpp"
#include "../vulkan/vk_sdk_platform.h"

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
