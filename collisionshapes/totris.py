#!/usr/bin/python
import os
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
index = 0
index2 = 0
skipfirst = True
outfile = open("tmp.dat", "w")
while True:
    index = points.find(", ")
    if index < 0:
        break
    x = points[0:index]
    index2 = points[index + 2:].find(", ")
    y = points[index + 2:index + 2 + index2]
    if not skipfirst:
        outfile.write(x + " " + y + " ")
    skipfirst = False
    points = points[index + 2 + index2 + 2:]
        
outfile.close()
