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
afterFirst = points[points.find(" ")+1:]

print(afterFirst[afterFirst.find(" ")+1:])

