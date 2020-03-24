
if (NOT TARGET Qt5::uic)
    add_executable(Qt5::uic IMPORTED)
if(WIN32)
    set(imported_location "${_qt5Widgets_install_prefix}/../../bin/windows/uic.exe")
    _qt5_Widgets_check_file_exists(${imported_location})
endif(WIN32)

if(UNIX)
    set(imported_location "${_qt5Widgets_install_prefix}/../../bin/linux/uic")
    _qt5_Widgets_check_file_exists(${imported_location})
endif(UNIX)
    set_target_properties(Qt5::uic PROPERTIES
        IMPORTED_LOCATION ${imported_location}
    )
endif()

include("${CMAKE_CURRENT_LIST_DIR}/Qt5Widgets_AccessibleFactory.cmake" OPTIONAL)

set(Qt5Widgets_UIC_EXECUTABLE Qt5::uic)
