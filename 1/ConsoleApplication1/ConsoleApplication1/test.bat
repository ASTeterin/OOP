@echo off

SET PROGRAM="%~1"
SET INPUT_FILE="input.txt"
SET OUT="%TEMP%\out.txt"
echo %OUT%
echo %INPUT_FILE%

%PROGRAM% %INPUT_FILE% "номер первой строки" > %OUT% || goto ERR
fc %OUT% 18.txt


echo All tests passed
exit /B 0


:ERR 
echo Program testing failed
exit /B 1