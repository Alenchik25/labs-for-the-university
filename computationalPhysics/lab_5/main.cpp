/* Объяснение работы в EXPLANATION.md */

#include <cmath>
#include <iostream>

using namespace std;

double func(double x) { return ((x * 0.5) + 1) * sin(x * 0.5); }

void rectangleMethod(double a, double b, int n) {
  double s = 0.0, h;
  h = (b - a) / n;
  for (int i = 0; i < n; i++) {
    s += func(a + i * h) * h;
  }
  cout << "Integral = " << s << endl;
  cout << "================\n";
}

void trapezoidMethod(double a, double b, int n) {
  double sum, h;

  h = (b - a) / n;

  sum = (func(a) + func(b)) * 0.5;

  for (int i = 1; i < n; i++) {
    sum += func(a + i * h);
  }

  sum *= h;
  cout << "Integral =: " << sum << endl;
  cout << "================\n";
}

void simpsonMethod(double a, double b, int n) {
  double h = (b - a) / n;
  double sum = func(a) + func(b);

  for (int i = 1; i < n; i += 2) {
    sum += 4 * func(a + i * h);
  }

  for (int i = 2; i < n - 1; i += 2) {
    sum += 2 * func(a + i * h);
  }

  double result = (h / 3) * sum;
  cout << "Integral = " << result << endl;
  cout << "================\n";
}

int main() {
  double a, b;
  int n, selector;

  cout << "Enter lower limit of integration: ";
  cin >> a;

  cout << "Enter upper limit of integration: ";
  cin >> b;

  cout << "Enter number of splits: ";
  cin >> n;

  cout << "================\n";
  cout << "Choose method:\n";
  cout << "1. Rectangle method\n";
  cout << "2. Trapezoid method\n";
  cout << "3. Simpson's method\n";

  cin >> selector;

  switch (selector) {
    case 1:
      cout << "Now using Rectangle Method" << endl;
      rectangleMethod(a, b, n);
      main();
      break;

    case 2:
      cout << "Now using Trapezoid Method" << endl;
      trapezoidMethod(a, b, n);
      main();
      break;

    case 3:
      cout << "Now using Simpson Method" << endl;
      simpsonMethod(a, b, n);
      main();
      break;

    default:
      cout << "Input error\n";
      break;
  }

  return 0;
}