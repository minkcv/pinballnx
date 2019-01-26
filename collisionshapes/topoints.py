#!/usr/bin/python
import os
file = open("tmp.svg", "r")
points = ""
found = False
done = False
for line in file:
	if "d=\"" in line:
		found = True
	if found and not done:
		points += line[line.find("d=\"")+3:line.find("z\"/>")] + " "
	if "z\"/>" in line:
		done = True
	

points = points.replace("M", "");
points = points.replace("l", "");
points = points.replace("  ", " ");
points = points.replace(" ", ", ");
print(points)

