/* Объяснение работы в EXPLANATION.md */

#include <iostream>
#include <vector>

using namespace std;

const double EPS = 1e-10;

int main() {
  vector<vector<double>> a = {
    {0.86, -0.02, -0.13, -0.15, 0.84},
    {-0.02, 0.95, -0.04, 0.48, 0.09},
    {-0.13, -0.04, 0.79, -0.09, 1.23},
    {-0.15, 0.48, -0.09, 0.81, 0.75}};

  int n = a.size();

  // Прямой ход метода Гаусса
  for (int i = 0; i < n; i++) {
    int row = i;
    for (int j = i + 1; j < n; j++) {
      if (abs(a[j][i]) > abs(a[row][i])) {
        row = j;
      }
    }
    swap(a[i], a[row]);

    if (abs(a[i][i]) < EPS) {
      cout << "System of equations is degenerate" << endl;
      return 0;
    }

    for (int j = n; j >= i; j--) {
      a[i][j] /= a[i][i];
    }

    for (int j = i + 1; j < n; j++) {
      for (int k = n; k >= i; k--) {
        a[j][k] -= a[i][k] * a[j][i];
      }
    }
  }

  // Обратный ход метода Гаусса
  for (int i = n - 1; i > 0; i--) {
    for (int j = i - 1; j >= 0; j--) {
      for (int k = n; k >= i; k--) {
        a[j][k] -= a[i][k] * a[j][i];
      }
    }
  }

  cout << "System solution:\n";
  for (int i = 0; i < n; ++i) {
    cout << "X" << i + 1 << " = " << a[i][n] << endl;
  }

  return 0;
}
