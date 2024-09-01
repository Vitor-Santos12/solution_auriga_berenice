#ifndef INPUT_FILE_VERIFIER_H
#define INPUT_FILE_VERIFIER_H

#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

using namespace std;

bool verifierInputFile(const std::string &filename) {
  ifstream input(filename);

  int L = 0;

  if (!input.is_open()) {
    std::cerr << "\nErro ao abrir o arquivo " << filename << std::endl;
    return false;
  }

  std::string line;
  int lineNumber = 0;

  if (std::getline(input, line)) {
    lineNumber++;

    std::istringstream iss(line);
    if (!(iss >> L) || L <= 0 || L > 1000) {
      std::cerr << "\nERROR " << lineNumber << ": invalid L size!" << std::endl;
      return false;
    }
  } else {
    std::cerr << "\nERROR: file is empty." << std::endl;
    return false;
  }

  int N;
  if (std::getline(input, line)) {
    lineNumber++;
    std::istringstream iss(line);
    if (!(iss >> N) || N <= 0 || N > 100) {
      std::cerr << "\nERROR line n °" << lineNumber << ": N is invalid!"
                << std::endl;
      return false;
    }
  } else {
    std::cerr << "\nERROR: data incomplete!" << std::endl;
    return false;
  }

  for (int i = 0; i < N; ++i) {
    lineNumber++;
    if (!std::getline(input, line)) {
      std::cerr << "\nERROR line n° " << lineNumber << ": data incomplete!"
                << std::endl;
      return false;
    }

    std::istringstream iss(line);
    double x0, y0, x1, y1;
    if (!(iss >> x0 >> y0 >> x1 >> y1)) {
      std::cerr << "\nERROR line n° " << lineNumber
                << ": Coordenate's format invalid!" << std::endl;
      return false;
    }

    L = 1000;
    
    if (x0 < 0 || x0 > L || y0 < 0 || y0 > L || x1 < 0 || x1 > L || y1 < 0 ||
        y1 > L) {
      std::cerr << "\nERROR line n° " << lineNumber
                << ": out of coordenate's limit! " << std::endl;
      return false;
    }
  }

  if (std::getline(input, line)) {
    std::cerr << "\nERROR: extra data." << lineNumber << "." << std::endl;
    return false;
  }

  input.close();
  std::cout << "\nFile " << filename << " verified with sucessful!"
            << std::endl;
  return true;
}

#endif
