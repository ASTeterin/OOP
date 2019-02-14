@echo off

SET PROGRAM="%~1"
SET INPUT_FILE="input.txt"
SET BAD_INPUT_FILE="bad_input.txt"
SET OUT="%TEMP%\out.txt"
::echo %OUT%
::echo %INPUT_FILE%

%PROGRAM% "empty.txt" "finish university" > %OUT% || goto ERR
fc %OUT% empty_out.txt

%PROGRAM% "finish university" > %OUT%
if NOT ERRORLEVEL 1 goto ERR
fc %OUT% no_param_out.txt

%PROGRAM% %BAD_INPUT_FILE% "finish university" > %OUT%
if NOT ERRORLEVEL 1 goto ERR
fc %OUT% bad_file_out.txt

%PROGRAM% %INPUT_FILE%> %OUT%
if NOT ERRORLEVEL 1 goto ERR
fc %OUT% no_param_out.txt

%PROGRAM% %INPUT_FILE% "finish university" > %OUT% || goto ERR
fc %OUT% 7.txt

%PROGRAM% %INPUT_FILE% "I learned to speak German" > %OUT% || goto ERR
fc %OUT% 14_31.txt




echo All tests passed
exit /B 0


:ERR 
echo Program testing failed
exit /B 1