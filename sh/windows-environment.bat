@echo off
setlocal enabledelayedexpansion

cd ".."
set QT=%CD%\thirdparty\qt\msvc2019_64\bin

REM 새로운 환경 변수 설정
reg add "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Session Manager\Environment" /v "PATH" /t REG_EXPAND_SZ /d "%PATH%;!QT!" /f

echo probably reflected
