#include <cmath>
#include <iostream>

using namespace std;

double func(double x) { return pow(x, 2) * log(x) - 2; }

double funcDerivative(double x) { return 2 * x - 1 / x; }

void newtonMethod(double x0, double epsilon) {
  int count = 0;
  while (abs(func(x0)) > epsilon) {
    x0 = x0 - func(x0) / funcDerivative(x0);
    count++;
  }
  cout << "Newton method solution: " << x0 << endl;
  cout << "Iterations: " << count << endl;
}

int main() {
  int count = 0;
  double epsilon[] = {1e-1, 1e-2, 1e-3, 1e-4, 1e-5,
                      1e-6, 1e-7, 1e-8, 1e-9, 1e-10},
         a;

  cout << "Enter variable value: ";  // Просим пользователя ввести значение переменной
  cin >> a;
  for (int i = 0; i < 10; i++) {
    cout << "=======\n"
         << "For epsilon " << epsilon[i] << endl;
    newtonMethod(a, epsilon[i]);
  }

  return 0;
}