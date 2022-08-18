#!/bin/bash
f1=main.cpp
f2=Int.cpp
f3=Int.h
if [ -f "$f1" ] &&  [ -f "$f2" ] && [ -f "$f3" ];
then g++ -o output.o Int.cpp main.cpp 
	if [ -f "output.o" ]; then echo compilation comple! 
	fi
else echo some files are missing!
fi
