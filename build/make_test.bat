echo
cmake -DCMAKE_BUILD_TYPE=Debug -G "MinGW Makefiles" ..
mingw32-make
xcopy "../lib/libs for win/debug" "../build" /H /Y /C
rd /s /q CMakeFiles
rd /s /q RGExx_autogen
del cmake_install.cmake
del CMakeCache.txt
del Makefile
mkdir resources
xcopy "../resources" "../build/resources" /H /Y /C
pause