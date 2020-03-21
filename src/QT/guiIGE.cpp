#include "guiIGE.h"

void GuiIGE::createContextGui(GLFWwindow *window, const char* glsl_version){
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window,true);
    ImGui_ImplOpenGL3_Init(glsl_version);
}

void GuiIGE::guiDraw(int width, int height,float red,
    float green, float blue, float alpha){
    glViewport(0,0, width,height);
    glClearColor(red,green,blue,alpha);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}