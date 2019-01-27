#!/bin/sh
FILE=$1
if [ "$FILE" = "" ]; then
    echo "usage: ./imgtotris.sh myimage.bmp"
    exit
fi
potrace -a 0 $FILE -b svg -o tmp.svg
./totris.py 
./poly2tri/build/p2t ./tmp.dat 0 0 1
