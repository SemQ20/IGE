#ifndef GLMAINWINDOW_H
#define GLMAINWINDOW_H


#include "../gl3w/gl3w.h"    // Initialize with gl3wInit()
#include "GLFW/glfw3.h"
#include <stdio.h>



class GLWindow {
public:
    void setDigitCapacity(int digitCapacity);
    int createGLWindow(int hGlWin,int wGlWin, const char *title,
    GLFWmonitor* monitor, GLFWwindow* share);
    ~GLWindow();
    GLFWwindow* window;
    int _hGlWin;
    int _wGlWin;
    const char* _title;
    GLFWmonitor* _monitor;
    GLFWwindow* _share;
    const char* glsl_version = "#version 130";

private:
    unsigned int _digitCapacity;
    unsigned int _glMainWinContextVersionMajor = 3;
    unsigned int _glMainWinContextVersionMinor = 3;
    bool err;
};
#endif