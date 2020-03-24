if(WIN32)
    set(_qt5_corelib_extra_includes "${_qt5Core_install_prefix}/cmake/win32-g++")
endif(WIN32)

if(UNIX)
    set(_qt5_corelib_extra_includes "${_qt5Core_install_prefix}/cmake/linux-g++")
endif(UNIX)