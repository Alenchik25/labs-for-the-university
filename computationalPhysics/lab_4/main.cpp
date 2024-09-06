#include <cmath>
#include <iostream>

using namespace std;

double func(double x) { return pow(x, 2) * log(x) - 2; }

double funcDerivative(double x) { return 2 * x - 1 / x; }

void RybakovMethod(double a, double b, double epsilon) {
  int iterations = 0;
  double x, x0, f, f0;
  do {
    x0 = a;
    f0 = func(x0);
    x = (a * func(b) - b * func(a)) / (func(b) - func(a));
    if (func(a) * func(x) < 0) {
      b = x;
    } else {
      a = x;
    }
    f = func(x);
    iterations++;
  } while (abs(x - x0) >= epsilon && abs(f - f0) >= epsilon);

  cout << "Rybakov's method solution: " << x0 << endl;
  cout << "Iterations: " << iterations << endl;
};

int main(int argc, char **argv) {
  double epsilon[] = {1e-1, 1e-2, 1e-3, 1e-4, 1e-5,
                      1e-6, 1e-7, 1e-8, 1e-9, 1e-10};
  double a = 1, b = 10;
  for (int i = 0; i < 10; i++) {
    cout << "=======\n"
         << "For epsilon " << epsilon[i] << endl;
    RybakovMethod(a, b, epsilon[i]);
  }

  return 0;
}