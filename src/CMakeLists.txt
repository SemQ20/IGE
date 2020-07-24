if(WIN32)
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
#SDL2 cmake config dir
set(SDL2_DIR "../cmake/SDL2")
endif(WIN32)

#include all source files
file(GLOB QT_SRC ${PROJECT_SOURCE_DIR}/src/QT/*cpp)
file(GLOB GL3W_SRC ${PROJECT_SOURCE_DIR}/src/gl3w/*.c)
file(GLOB GUI_SRC ${PROJECT_SOURCE_DIR}/src/imgui/*.cpp)
file(GLOB SDL2_SRC ${PROJECT_SOURCE_DIR}/src/SDL2/*.c)

set(MAIN_SOURCES main.cpp)

FIND_PACKAGE(Vulkan REQUIRED)
IF(WIN32 AND NOT MSVC)
   GET_FILENAME_COMPONENT(Vulkan_LIBRARY_DIR ${Vulkan_LIBRARY} DIRECTORY)
    IF(NOT "${Vulkan_LIBRARY_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
       MESSAGE(WARNING "If linking to Vulkan fails, try copying vulkan-1.dll to the ${CMAKE_BINARY_DIR} and then set Vulkan_LIBRARY to ${CMAKE_BINARY_DIR}/vulkan-1.dll")
    ENDIF(NOT "${Vulkan_LIBRARY_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
ENDIF(WIN32 AND NOT MSVC)

add_executable(${TARGET} WIN32
    ${MAIN_SOURCES} 
    ${QT_SRC} 
    ${GL3W_SRC} 
    ${GUI_SRC}
    ${SDL2_SRC}
)
#win32 delete console from application
#in other system variable = win32 was ignored

#bloc of code for required components
#find Qt5 components/libs
find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Core REQUIRED)
find_package(Qt5 COMPONENTS Gui REQUIRED)

#find OpenGL library
find_package(OpenGL REQUIRED)
#find glfw3 library
find_package(glfw3 REQUIRED)
#find SDL library
find_package(SDL2 REQUIRED)
#find OpenAl library
find_package(OpenAL REQUIRED)

#links all libraries to project
target_link_libraries(${TARGET} PRIVATE Qt5::Widgets)
target_link_libraries(${TARGET} PRIVATE Qt5::Core)
target_link_libraries(${TARGET} PRIVATE Qt5::Gui)
target_link_libraries(${TARGET} PRIVATE OpenGL::GL)
target_link_libraries(${TARGET} PRIVATE glfw3)
target_link_libraries(${TARGET} PRIVATE ${Vulkan_LIBRARY})
target_link_libraries(${TARGET} PRIVATE SDL2)

if(WIN32)
    target_link_libraries(${TARGET} PRIVATE gdi32)
    target_link_libraries(${TARGET} PRIVATE openal32)
endif(WIN32)

if(UNIX)
    target_link_libraries(${TARGET} PRIVATE X11)
    target_link_libraries(${TARGET} PRIVATE openal)
    target_link_libraries(${TARGET} PRIVATE pthread)
    target_link_libraries(${TARGET} PRIVATE dl)
    endif(UNIX)