#include "scene.hpp"
#include "guiIGE.h"

void IGE::Scene::createScene(GLWindow glMWind,int height, int weight, const char* title,
        GLFWmonitor* monitor, GLFWwindow* share){
        
    glMWind.createGLWindow(height,weight,title,monitor,share);
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