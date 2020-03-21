#ifndef GUIIGE_H
#define GUIIGE_H
#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_glfw.h"
#include "../imgui/imgui_impl_opengl3.h"
#include "../gl3w/gl3w.h"    // Initialize with gl3wInit()
#include "GLFW/glfw3.h"

namespace  GuiIGE {
    void createContextGui(GLFWwindow *window, const char* glsl_version);
    void guiDraw(int width, int height, float red,
    float green, float blue, float alpha);
};

#endif