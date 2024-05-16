#include <cmath>
#include <iostream>

using namespace std;

double func(double x) { return pow(x, 2) * log(x) - 2; }

int main() {
  int count = 0;
  double epsilon, a = 1, b = 10, c;

  cout << "Enter epsilon value: "; // Просим пользователя ввести значение точности
  cin >> epsilon;

  while ((b - a) > epsilon) {
    c = (a + b) * 0.5; // Находим середину интервала [a, b]

    if (func(c) * func(a) < 0) {
      b = c;
    } else {
      a = c;
    }
    count++;
  }

  cout << "Solution for equation: " << c << endl;
  cout << "Number of intervals: " << count << endl;
  
  return 0;
}