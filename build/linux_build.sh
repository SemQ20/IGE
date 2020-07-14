# !/usr/bash
cmake -DCMAKE_BUILD_TYPE=Release  -B Release -G "Unix Makefiles" ..
make --directory=Release
cd Release



