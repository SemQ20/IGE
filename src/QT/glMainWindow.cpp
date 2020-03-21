#include "glMainWindow.h"

void glfw_error_callback(int error, const char* description){
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

int GLWindow::createGLWindow(int hGlWin,int wGlWin, const char *title,
    GLFWmonitor* monitor, GLFWwindow* share) {
        glfwSetErrorCallback(glfw_error_callback);
        if(!glfwInit()) { return 1; }
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,_glMainWinContextVersionMajor);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,_glMainWinContextVersionMinor);
            window = glfwCreateWindow(hGlWin,wGlWin,title,monitor,share);
        if(window==NULL){ return 1;}
            glfwMakeContextCurrent(window);
            glfwSwapInterval(1);
            _hGlWin=hGlWin;
            _wGlWin=wGlWin;
            _title=title;
            _monitor=monitor;
            _share=share;
        err = gl3wInit() != 0;
        if (err)
        {
            fprintf(stderr, "Failed to initialize OpenGL loader!\n");
            return 1;
        }
        return 0;
}

GLWindow::~GLWindow(){
    glfwDestroyWindow(window);
    glfwTerminate();
}