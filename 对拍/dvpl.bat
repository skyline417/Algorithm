@echo off 
:loop
std.exe
mine.exe
fc std.out mine.out
if not errorlevel 1 goto loop
pause
:end