#ifndef INPUT_FILE_GENERATOR_H
#define INPUT_FILE_GENERATOR_H

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

using namespace std;

void generateInputFile(const string &filename) {
  srand(static_cast<unsigned int>(time(nullptr)));
  
  ofstream output(filename);

  if (!output) {
      cerr << "Error: Unable to open the file " << filename << endl;
      return;
  }

  int L = rand() % 1000 + 1;
  output << L << endl;

  int N = rand() % 100 + 1;
  output << N << endl;

  for (int i = 0; i < N; ++i) {
    double x0 = static_cast<double>(rand() % (L * 100 + 1)) / 100.0;
    double y0 = static_cast<double>(rand() % (L * 100 + 1)) / 100.0;
    double x1 = static_cast<double>(rand() % (L * 100 + 1)) / 100.0;
    double y1 = static_cast<double>(rand() % (L * 100 + 1)) / 100.0;
    output << x0 << " " << y0 << " " << x1 << " " << y1 << endl;
  }

  output.close();

  cout << "File " << filename << " generate with Sucessful!" << endl;
}

#endif
