@echo off

SET PROGRAM="%~1"
SET OUT="%TEMP%\out.txt"

%PROGRAM% > %OUT%
if NOT ERRORLEVEL 1 goto ERR
fc %OUT% no_param_out.txt
if ERRORLEVEL 1 goto ERR



echo All tests passed
exit /B 0


:ERR 
echo Program testing failed
exit /B 1