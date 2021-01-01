#!/bin/sh
#clear
if (g++ -o $1 $1.cpp -Wall -lm -g) then
   echo "### COMPILOU ###"
   if !(./$1 < $input.txt) then
   echo "### RUNTIME ERROR"
   fi
fi
