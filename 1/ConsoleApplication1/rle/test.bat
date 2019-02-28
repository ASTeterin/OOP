@echo off

SET PROGRAM="%~1"
SET OUT="%TEMP%\out.txt"

%PROGRAM% > %OUT%
if NOT ERRORLEVEL 1 goto ERR
fc %OUT% invalid_arg.txt
if ERRORLEVEL 1 goto ERR

 %PROGRAM% qwerty input.txt output.txt > %OUT%
 if NOT ERRORLEVEL 1 goto ERR
 fc %OUT% wrong_mode.txt
 if ERRORLEVEL 1 goto ERR

if exist no_existing_file.txt del no_existing_file.txt
%PROGRAM% "pack" no_existing_file.txt output.txt > %OUT%
if NOT ERRORLEVEL 1 goto ERR
fc %OUT% no_input_file.txt
if ERRORLEVEL 1 goto ERR

%PROGRAM% "pack" test1.png output.txt || goto ERR
fc output.txt test1_out.bin
if ERRORLEVEL 1 goto ERR

%PROGRAM% "unpack" test1_out.bin output.png || goto ERR
fc output.png test1.png
if ERRORLEVEL 1 goto ERR


echo All tests passed
exit /B 0


:ERR 
echo Program testing failed
exit /B 1