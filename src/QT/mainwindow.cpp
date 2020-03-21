
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "QtCore/QUrl"
#include "QtGUI/QDesktopServices"
#include "glMainWindow.h"
#include "guiIGE.h"

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
    glMWind.createGLWindow(1280,720,"Window",NULL,NULL);
    GuiIGE::createContextGui(glMWind.window,glMWind.glsl_version);
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
     while(!glfwWindowShouldClose(glMWind.window)){
         glfwPollEvents();
         ImGui_ImplOpenGL3_NewFrame();
         ImGui_ImplGlfw_NewFrame();
         ImGui::NewFrame();
         {
            ImGui::Begin("Hello");
            ImGui::End(); 
         }
         ImGui::Render();
         GuiIGE::guiDraw(glMWind._hGlWin,glMWind._wGlWin,clear_color.x,
         clear_color.y,clear_color.z,clear_color.w);
         glfwSwapBuffers(glMWind.window);
    }
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
        glfwDestroyWindow(glMWind.window);
        glfwTerminate();
}