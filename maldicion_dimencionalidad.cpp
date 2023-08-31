#include <fstream>
#include <iostream>
#include <math.h>
#include <random>
#include <vector>

using namespace std;

int main() {
  int dimension = 1000; // Cambia este valor a la dimensión deseada

  vector<vector<float>> vec;
  vector<float> var;
  random_device rd;
  mt19937 gen(rd());
  uniform_real_distribution<> dis(0.0, 1.0);

  for (int n = 0; n < 100; ++n) {
    var.clear();
    for (int d = 0; d < dimension; ++d) {
      var.push_back(dis(gen)); // Generar coordenada aleatoria en cada dimensión
    }
    vec.push_back(var);
  }

  vector<float> distances;

  for (int i = 0; i < 100; ++i) {
    for (int j = i; j < 100; ++j) {
      float dist = 0.0;
      for (int d = 0; d < dimension; ++d) {
        dist += pow(vec[i][d] - vec[j][d], 2);
      }
      dist = sqrt(dist);
      distances.push_back(dist);
    }
  }

  ofstream fw(to_string(dimension) + ".txt", ofstream::out);
  int i = 0;
  if (fw.is_open()) {
    while (i < (100 * (100 + 1)) / 2) { // Se ajusta para cualquier dimensión
      fw << distances[i] << "\n";
      i++;
    }
    fw.close();
  }
  return 0;
}
