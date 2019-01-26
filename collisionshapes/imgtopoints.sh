#!/bin/sh
FILE=$1
if [ "$FILE" = "" ]; then
	echo "usage: ./imgtopoints.sh img.bmp"
	exit
fi
potrace -a 0 $FILE -b svg -o tmp.svg
./topoints.py 
