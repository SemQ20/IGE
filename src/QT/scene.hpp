#ifndef SCENE_HPP
#define SCENE_HPP

#include "glmainwindow.h"
#include <memory>
namespace IGE {
    namespace Scene{
        void createScene(GLWindow glMWind, int height, int weight, const char* title,
        GLFWmonitor* monitor, GLFWwindow* share);
    };
};

#endif