## Given Data 

```cpp
int N; // Number of Airplanes
double L; // Size Florest Area(Square)  
``` 

## Variables

```cpp
// Struct point for coordenates
struct Point {
    double x, y;
};

// Struct Line for Airplane Line 
struct Line {
    Point start, end;
};
```

## Process

1. Read the Input File (Variables: L, N and  x0, y0, x1 and y1);

```cpp
// File Handle
ifstream input("Task1_Forest_Fire/CODE/data/INPUT");
ofstream output("Task1_Forest_Fire/CODE/data/OUTPUT");

double L;
int N ;
input >> L >> N;
// Example of file
L = 120
N = 12
x0, y0, x1 and y1 = (17.4, 23, 33.27, 99.861) // respectively.
...
```
2. Loop to create coordenate's vetor for each plane;  
```c++ 
vector<Line> lines(N);
for (int i = 0; i < N; ++i) {
    input >> lines[i].start.x >> lines[i].start.y >> lines[i].end.x >> lines[i].end.y;
}
```
3. Build the Airplane's boundries based in your entry and exit coordenates, using this math expression to determinate the perpendicular line;

**Distance**

![alt text](<distance_expression.png>)

```c++
double calculatePerpendicularDistance(const Point& p, const Line& line) {
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
```

4. Function to check if a point is within the strip of visibility;

```cpp
bool isPointInStrip(const Point &p, const Line &line, double L) {
  // Calculate the perpendicular distance from the point to the line
  double distance = calculatePerpendicularDistance(p, line);

  // Check if the distance is within 50 km
  if (distance <= 50.0) {
    return true;
  } else {
    return false;
  }
}
```

5. Check if the entire square is covered;

```cpp

  bool fullyCovered = true;
  Point uncoveredPoint = {0, 0};

  for (double x = 0; x <= L; x += 0.01) {
    for (double y = 0; y <= L; y += 0.01) {
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
    
```
