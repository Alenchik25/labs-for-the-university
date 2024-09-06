/* Объяснение работы в EXPLANATION.md */

#include <cmath>
#include <iostream>

using namespace std;

double func(double x) { return pow(x, 2) * log(x) - 2; }

void chordMethod(double a, double b, double epsilon) {
  int count = 0;
  while (abs(b - a) > epsilon) {
    double next = b - (func(b) * (b - a)) / (func(b) - func(a));
    a = b;
    b = next;
    count++;
  }
  cout << "Chord method solution: " << b << endl;
  cout << "Iterations: " << count << endl;
}

int main() {
  int count = 0;
  double epsilon[] = {1e-1, 1e-2, 1e-3, 1e-4, 1e-5,
                      1e-6, 1e-7, 1e-8, 1e-9, 1e-10},
         a = 1, b = 10;
  for (int i = 0; i < 10; i++) {
    cout << "=======\n"
         << "For epsilon " << epsilon[i] << endl;
    chordMethod(a, b, epsilon[i]);
  }
  return 0;
}