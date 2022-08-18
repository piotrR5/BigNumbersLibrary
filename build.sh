#!/bin/bash
if [-f main.cpp] &&  [-f Int.cpp] && [-f Int.h]
	g++ -o output.o Int.cpp main.cpp 
elif
	echo some files are missing!
fi
