echo
cmake -B Debug -DCMAKE_BUILD_TYPE=Debug -G "MinGW Makefiles" ..
mingw32-make --directory=Debug
cd Debug
rd /s /q CMakeFiles
rd /s /q RGExx_autogen
del cmake_install.cmake
del CMakeCache.txt
del Makefile
cd ..
xcopy "../lib/libs for win/release" "../build/Debug" /H /Y /C /E
cd Debug
mkdir resources
xcopy "../../resources" "../Debug/resources" /H /Y /C
cd src
copy IGE.exe ..
cd ..
pause