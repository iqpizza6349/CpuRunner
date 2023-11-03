@echo off
echo Removing build directory...
@RD /S /Q "D:\CpuRunner\build"

echo Remake 'build' directory...
md "D:\CpuRunner\build"

cd "../build"

echo Build project by CMake...
cmake ..

echo Make Debug binary file(.exe) by CMake...
cmake --build . 

echo done!
