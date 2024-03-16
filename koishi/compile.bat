@echo off

g++ main.cpp -o run.exe -lgdi32 -lwinmm
cd bin
7z a -mx=0 ../bin.7z ../run.exe ../music.wav ../pic1.bmp
cd ..
copy /b bin\7zs.sfx + config.txt + bin.7z koishi.exe
del run.exe bin.7z


pause