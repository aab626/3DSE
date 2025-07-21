@echo off
REM filepath: c:\Users\a626\projects\space_game\build_engine.bat

REM Set project root (edit this path if your project moves)
set PROJECT_ROOT=C:\Users\a626\projects\space_game

REM Remove build directory safely
if exist "%PROJECT_ROOT%\build" rmdir /S /Q "%PROJECT_ROOT%\build"
mkdir "%PROJECT_ROOT%\build"
cd "%PROJECT_ROOT%\build"

REM Configure project
cmake "%PROJECT_ROOT%\engine" -G "Visual Studio 17 2022" -A x64

REM Build project
cmake --build . --config Debug

cd "%PROJECT_ROOT%"
echo Build finished!