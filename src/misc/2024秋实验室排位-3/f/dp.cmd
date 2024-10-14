@echo off

:loop

python dm.py > indp
1.exe < indp

goto loop
