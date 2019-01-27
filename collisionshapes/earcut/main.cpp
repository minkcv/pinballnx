#include <earcut.hpp>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// The number type to use for tessellation
using Coord = double;

// The index type. Defaults to uint32_t, but you can also pass uint16_t if you know that your
// data won't have more than 65536 vertices.
using N = uint32_t;

// Create array
using Point = std::array<Coord, 2>;
std::vector<std::vector<Point>> polygon;

int main(){
    // Fill polygon structure with actual data. Any winding order works.
    // The first polyline defines the main polygon.
    //polygon.push_back({{100, 0}, {100, 100}, {0, 100}, {0, 0}});
    ifstream input;
    string line;
    input.open("tmp.dat");
    vector<Point> poly1;
    if (input.is_open()) {
        while (getline(input, line)) {
            // Yes, it's inefficient, but this is not at the runtime of the game I'm making so I'm not going to optimize it.
            double x;
            double y;
            bool xTurn = true;
            size_t index = 0;
            size_t nextIndex = line.find(" ");
            while (true) {
                string coord = line.substr(index, nextIndex - index);
                if (coord.length() == 0)
                    break;
                index = nextIndex + 1;
                nextIndex = line.substr(index, string::npos).find(" ") + index;
                double coordDbl = atof(coord.c_str());
                if (xTurn) {
                    x = coordDbl;
                }
                else {
                    y = coordDbl;
                    poly1.push_back({x, y});
                }
                xTurn = !xTurn;
            }
        }
    }
    input.close();
    polygon.push_back(poly1);

    // Run tessellation
    // Returns array of indices that refer to the vertices of the input polygon.
    // e.g: the index 6 would refer to {25, 75} in this example.
    // Three subsequent indices form a triangle. Output triangles are clockwise.
    std::vector<N> indices = mapbox::earcut<N>(polygon);

    // Output the points
    cout << "Number of points:" << indices.size() << endl;
    vector<Point> poly = polygon.at(0);
    for (int ind = 0; ind < indices.size(); ind++) {
        Point pt = poly.at(indices.at(ind));
        cout << pt[0] << ", " << pt[1] << ", ";
    }
    cout << endl;
}