#!/usr/bin/python
import os
import sys
file = open("tmp.svg", "r")
points = ""
found = False
done = False
for line in file:
    if found and not done:
        points += line[:line.find("z\"/>")] + " "
    elif "d=\"" in line:
        found = True
        points += line[line.find("d=\"M")+3:line.find("z\"/>")] + " "
    if "z\"/>" in line:
        done = True

points = points.replace("M", "")
points = points.replace("l", "")
points = points.replace("  ", " ")
points = points.replace(" ", ", ")
points = points.replace("\n", "")
x = ""
y = ""
xTotal = 0.0
yTotal = 0.0
index = 0
index2 = 0
if len(sys.argv) < 1:
    print("usage: ./totris.py <comma> \n where <comma> is 0 or 1 to choose commas after coordinates")
    quit()

comma = sys.argv[0] == 1
outfile = open("tmp.dat", "w")
while True:
    index = points.find(", ")
    if index < 0:
        break
    x = points[0:index]
    index2 = points[index + 2:].find(", ")
    y = points[index + 2:index + 2 + index2]
    xTotal += float(x)
    yTotal += float(y)
    if comma:
        outfile.write(str(xTotal) + ", " + str(yTotal) + ", ")
    else:
        outfile.write(str(xTotal) + " " + str(yTotal) + " ")
    points = points[index + 2 + index2 + 2:]
        
outfile.close()
