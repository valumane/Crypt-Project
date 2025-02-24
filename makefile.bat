@echo off
gcc %1 -o %~n1 -g -Wall -Wextra -Wpedantic -O3
%~n1.exe
