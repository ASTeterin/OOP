@echo off

SET PROGRAM="%~1"
SET OUT="%TEMP%\out.txt"

%PROGRAM% > %OUT%
if NOT ERRORLEVEL 1 goto ERR
fc %OUT% no_param_out.txt
if ERRORLEVEL 1 goto ERR

