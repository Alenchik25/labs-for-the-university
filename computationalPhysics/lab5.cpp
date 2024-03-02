#include <cmath>
#include <iostream>

using namespace std;

double func(double x) { return ((x * 0.5) + 1) * sin(x * 0.5); }

void rectangleMethod(double a, double b) {
    double s = 0.0, h;
    int n;
    cout << "Input N: ";
    cin >> n;
    h = (b - a) / double(n);
    for (int i = 0; i < n; i++){
        s += func(a + i * h) * h;
    }
}

int main() {
  int a = 1, b = 2;
  return 0;
}