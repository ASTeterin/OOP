@echo off

SET PROGRAM="%~1"
SET OUT="%TEMP%\out.txt"
SET BAD_INPUT_FILE="no_existing_file.txt" 

%PROGRAM% > %OUT%
if NOT ERRORLEVEL 1 goto ERR
fc %OUT% no_param_out.txt
if ERRORLEVEL 1 goto ERR

%PROGRAM% %BAD_INPUT_FILE% "matrix2.txt" > %OUT%
if NOT ERRORLEVEL 1 goto ERR
fc %OUT% bad_input_file1.txt
if ERRORLEVEL 1 goto ERR

%PROGRAM% "matrix1.txt" %BAD_INPUT_FILE% > %OUT%
if NOT ERRORLEVEL 1 goto ERR
fc %OUT% bad_input_file2.txt
if ERRORLEVEL 1 goto ERR

%PROGRAM% "invalid_format_matrix1.txt" "matrix2.txt" > %OUT%
if NOT ERRORLEVEL 1 goto ERR
fc %OUT% invalid_format.txt
if ERRORLEVEL 1 goto ERR

%PROGRAM% "matrix1.txt" "invalid_format_matrix1.txt" > %OUT%
if NOT ERRORLEVEL 1 goto ERR
fc %OUT% invalid_format.txt
if ERRORLEVEL 1 goto ERR

%PROGRAM% "matrix1.txt" "matrix2.txt" > %OUT% || goto ERR
fc %OUT% resultMatrix.txt
if ERRORLEVEL 1 goto ERR



echo All tests passed
exit /B 0


:ERR 
echo Program testing failed
exit /B 1