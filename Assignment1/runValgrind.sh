#!/bin/bash

if [ "$#" -ne 1 ];

then

     echo "usage: runValgrind.sh ./cExecutable"

else

     eval "valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes $1"

fi