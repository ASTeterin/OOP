@echo off

SET PROGRAM="%~1"
SET OUT="%TEMP%\out.txt"

%PROGRAM% > %OUT%
if NOT ERRORLEVEL 1 goto ERR
fc %OUT% no_param_out.txt
if ERRORLEVEL 1 goto ERR

%PROGRAM%  101010101010101010101110000001111100011011000011110010 > %OUT%
if NOT ERRORLEVEL 1 goto ERR
fc %OUT% out_of_range_out.txt
if ERRORLEVEL 1 goto ERR

%PROGRAM% 12345 > %OUT%
if NOT ERRORLEVEL 1 goto ERR
fc %OUT% bad_format_out.txt
if ERRORLEVEL 1 goto ERR

%PROGRAM% 101 > %OUT%
if ERRORLEVEL 1 goto ERR
fc %OUT% 5.txt
if ERRORLEVEL 1 goto ERR


echo All tests passed
exit /B 0


:ERR 
echo Program testing failed
exit /B 1