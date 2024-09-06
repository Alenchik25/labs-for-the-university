/* Объяснение работы в EXPLANATION.md */

#include <iostream>
#include <vector>

using namespace std;

double LagrangeInterpolationLinear(double x, const vector<double>& xData,
                                   const vector<double>& yData) {
  double result = 0.0;
  for (size_t i = 0; i < xData.size(); ++i) {
    double term = yData[i];
    for (size_t j = 0; j < xData.size(); ++j) {
      if (j != i) {
        term *= (x - xData[j]) / (xData[i] - xData[j]);
      }
    }
    result += term;
  }
  return result;
}

double LagrangeInterpolationQuadratic(double x, const vector<double>& xData,
                                      const vector<double>& yData) {
  double result = 0.0;
  for (size_t i = 0; i < xData.size(); ++i) {
    double term = yData[i];
    for (size_t j = 0; j < xData.size(); ++j) {
      if (j != i) {
        term *= (x - xData[j]) / (xData[i] - xData[j]);
      }
    }
    result += term;
  }
  return result;
}

int main() {
  vector<double> xData = {0.0, 0.3, 0.7};
  vector<double> yData = {2.0, 2.5, 2.9};

  // Линейный интерполяционный многочлен Лагранжа на промежутке от 0.3 до 0.7
  cout << "Linear Lagrange Interpolation polynomial in range of 0.3 to 0.7\n";
  for (double x = 0.3; x < 0.7 + 0.1; x += 0.1) {
    cout << "x = " << x
         << ", y = " << LagrangeInterpolationLinear(x, xData, yData) << "\n";
  }

  // Квадратичный интерполяционный многочлен Лагранжа на отрезке от 0 до 0.7
  cout << "Quadratic Lagrange interpolation polynomial on a segment from 0 to "
          "0.7\n";

  for (double x = 0.0; x < 0.7 + 0.1; x += 0.1) {
    cout << "x = " << x
         << ", y = " << LagrangeInterpolationQuadratic(x, xData, yData) << "\n";
  }

  return 0;
}