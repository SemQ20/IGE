#Qt5Widgets cmake config dir
set(Qt5Widgets_DIR "../cmake/Qt5Widgets")
#Qt5Core cmake config dir
set(Qt5Core_DIR "../cmake/Qt5Core")
#Qt5Gui cmake config dir
set(Qt5Gui_DIR "../cmake/Qt5Gui")
#Qt5 cmake config dir
set(Qt5_DIR "../cmake/Qt5")
#GLFW cmake config dir
set(glfw3_DIR "../cmake/GLFW")
#glm cmake config dir
set(glm_DIR "../cmake/glm")

#include all source files
file(GLOB QT_DIR ${PROJECT_SOURCE_DIR}/src/QT/*cpp)
file(GLOB GL3W_DIR ${PROJECT_SOURCE_DIR}/src/gl3w/*.c)
file(GLOB GUI_DIR ${PROJECT_SOURCE_DIR}/src/imgui/*.cpp)

set(MAIN_SOURCES main.cpp)

add_executable(${TARGET} WIN32
    ${MAIN_SOURCES} 
    ${QT_DIR} 
    ${GL3W_DIR} 
    ${GUI_DIR}
)
#win32 delete console from application
#in other system win32 was ignored

#bloc of code for required components
#find Qt5 components/libs
find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Core REQUIRED)
find_package(Qt5 COMPONENTS Gui REQUIRED)

#find OpenGL library
find_package(OpenGL REQUIRED)
#find glfw3 library
find_package(glfw3 REQUIRED)

#links all libraries to project
target_link_libraries(${TARGET} PRIVATE Qt5::Widgets)
target_link_libraries(${TARGET} PRIVATE Qt5::Core)
target_link_libraries(${TARGET} PRIVATE Qt5::Gui)
target_link_libraries(${TARGET} PRIVATE OpenGL::GL)
target_link_libraries(${TARGET} PRIVATE opengl32)
target_link_libraries(${TARGET} PRIVATE glfw3)
if(WIN32)
    target_link_libraries(${TARGET} PRIVATE gdi32)
endif(WIN32)

