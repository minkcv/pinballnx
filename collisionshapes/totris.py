#!/usr/bin/python
import os
import sys
file = open("tmp.svg", "r")
points = ""
found = False
done = False
yTransform = 0
for line in file:
    if "transform" in line:
        yTransform = float(line[line.find("<g transform=\"translate(0.000000,") + len("<g transform=\"translate(0.000000,"):line.find(")")])
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
# The svg has 0.1 for the scale and -y and a transform. Yikes
# Start the yTotal at the y transform
xTotal = 0.0
yTotal = yTransform
index = 0
index2 = 0
if len(sys.argv) < 2:
    print("usage: ./totris.py <comma> \n where <comma> is 0 or 1 to choose commas after coordinates")
    quit()

comma = sys.argv[1] == str(1)
outfile = open("tmp.dat", "w")
while True:
    index = points.find(", ")
    if index < 0:
        break
    x = points[0:index]
    index2 = points[index + 2:].find(", ")
    y = points[index + 2:index + 2 + index2]
    # divide by 10 to fix the 0.1 scale in the svg
    xTotal += float(x) / 10.0
    # substract here because the y is inverted in the svg (see transform)
    yTotal += -float(y) / 10.0

    # ignore small changes that box2d can't handle
    # you might have to fuss with this value depending on 
    # how jagged or smooth your shapes are
    ignoreDistance = 1
    if abs(float(x)) / 10.0 + abs(float(y)) / 10.0 < ignoreDistance:
        print("skipping " + x + " and " + y)
        points = points[index + 2 + index2 + 2:]
        continue
    if comma:
        outfile.write(str(xTotal) + ", " + str(yTotal) + ", ")
    else:
        outfile.write(str(xTotal) + " " + str(yTotal) + " ")
    points = points[index + 2 + index2 + 2:]
        
outfile.close()
