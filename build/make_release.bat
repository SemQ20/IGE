echo
cmake -B Release -DCMAKE_BUILD_TYPE=Release -G "MSYS Makefiles" ..
make --directory=Release
cd Release
rd /s /q CMakeFiles
rd /s /q RGExx_autogen
del cmake_install.cmake
del CMakeCache.txt
del Makefile
cd ..
xcopy "../lib/libs for win/release" "../build/Release" /H /Y /C /E
cd Release
mkdir resources
xcopy "../../resources" "../Release/resources" /H /Y /C
cd src
copy IGE.exe ..
cd ..
IGE
pause