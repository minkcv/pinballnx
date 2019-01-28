#!/bin/sh
FILE=$1
if [ "$FILE" = "" ]; then
    echo "usage: ./imgtopoints.sh myimage.bmp"
    exit
fi
potrace -a 0 $FILE -b svg -o tmp.svg
./totris.py 1
