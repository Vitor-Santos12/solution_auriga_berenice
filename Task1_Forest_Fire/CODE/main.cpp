#include <cmath>
#include <fstream>
#include <iostream>
#include <limits>
#include <vector>
#include <ctime>

#include "input_file_generator.h"
#include "input_file_verifier.h"

using namespace std;

struct Point {
  double x, y;
};

struct Line {
  Point start, end;
};

double calculatePerpendicularDistance(const Point &p, const Line &line) {
  double x0 = line.start.x;
  double y0 = line.start.y;
  double x1 = line.end.x;
  double y1 = line.end.y;
  double x = p.x;
  double y = p.y;

  double numerator = fabs((y1 - y0) * x - (x1 - x0) * y + x1 * y0 - y1 * x0);
  double denominator = sqrt((y1 - y0) * (y1 - y0) + (x1 - x0) * (x1 - x0));

  return numerator / denominator;
}

bool isPointInStrip(const Point &p, const Line &line, double L) {

  double distance = calculatePerpendicularDistance(p, line);

  // Check if the distance is within 50 km
  if (distance <= 50.0) {
    return true;
  } else {
    return false;
  }
}

int main() {
  //Generate random input_file
  /* generateInputFile("Task1_Forest_Fire/CODE/data/INPUT"); */

  //Verify the genereted file.
  bool isValid = verifierInputFile("Task1_Forest_Fire/CODE/data/INPUT");
  
  ifstream input("Task1_Forest_Fire/CODE/data/INPUT");

  ofstream output("Task1_Forest_Fire/CODE/data/OUTPUT");
  
  if (isValid) {
    
  double L;
  u_int N = 0;
  input >> L >> N;

  vector<Line> lines(N);
  for (u_int i = 0; i < N; ++i) {
    input >> lines[i].start.x >> lines[i].start.y >> lines[i].end.x >>
        lines[i].end.y;
  }

  bool fullyCovered = true;
  Point uncoveredPoint = {0, 0};

  for (double x = 0; x <= L; x += 0.1) {
    for (double y = 0; y <= L; y += 0.1) {
      Point p = {x, y};
      bool covered = false;
      for (const auto &line : lines) {
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
    if (!fullyCovered)
      break;
  }

  if (fullyCovered) {
    output << "OK" << endl;
  } else {
    output << uncoveredPoint.x << " " << uncoveredPoint.y << endl;
  }

  } else {
    output << "ERROR!" << endl; 
  }

  return 0;
}
