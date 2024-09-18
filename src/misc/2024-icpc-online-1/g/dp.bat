@echo off


:loop

python dm.py > indp
1.exe < indp > outdp1
bl.exe < indp > outdpbl

if not status run
 goto loop