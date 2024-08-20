#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

struct Point {
    double x, y;
};

struct Line {
    Point start, end;
};

// Function to check if a point is within the strip of visibility
bool isPointInStrip(const Point& p, const Line& line, double L) {
    // Implement the logic to check if point `p` is within the visible strip of `line`
    // Use geometrical calculations to determine if `p` lies within 50km of the line.
    return true; // Placeholder
}

int main() {
    ifstream input("INPUT");
    ofstream output("OUTPUT");

    double L;
    int N;
    input >> L >> N;

    vector<Line> lines(N);
    for (int i = 0; i < N; ++i) {
        input >> lines[i].start.x >> lines[i].start.y >> lines[i].end.x >> lines[i].end.y;
    }

    // Check if the entire square is covered
    bool fullyCovered = true;
    Point uncoveredPoint = {0, 0};

    for (double x = 0; x <= L; x += 0.001) {
        for (double y = 0; y <= L; y += 0.001) {
            Point p = {x, y};
            bool covered = false;
            for (const auto& line : lines) {
                if (isPointInStrip(p, line, L)) {
                    covered = true;
                    break;
                }
            }
            if (!covered) {
                uncoveredPoint = p;
                fullyCovered = false;
                break;
            }
        }
        if (!fullyCovered) break;
    }

    if (fullyCovered) {
        output << "OK" << endl;
    } else {
        output << uncoveredPoint.x << " " << uncoveredPoint.y << endl;
    }

    return 0;
}
