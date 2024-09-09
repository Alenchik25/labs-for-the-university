/* Объяснение работы в EXPLANATION.md */

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

const double EPSILON = 1e-9;

// Метод простых итераций
pair<vector<double>, int> simpleIterationMethod(const vector<vector<double>>& A,
                                     const vector<double>& b) {
  int n = A.size();
  vector<double> x(n, 0.0);
  int count = 0;
  while (true) {
  vector<double> new_x(n);
    for (int i = 0; i < n; ++i) {
      double sum = 0.0;
      for (int j = 0; j < n; ++j) {
        if (j != i) {
          sum += A[i][j] * x[j];
        }
      }
      new_x[i] = (b[i] - sum) / A[i][i];
    }

    double error = 0.0;
    for (int i = 0; i < n; ++i) {
      error = max(error, abs(new_x[i] - x[i]));
      x[i] = new_x[i];
    }
    count++;
    if (error < EPSILON) {
      break;
    }
  }

  return make_pair(x, count);
}


// Метод Гаусса-Зейделя
pair<vector<double>, int> gaussSeidelMethod(const vector<vector<double>>& A,
                                 const vector<double>& b) {
  int n = A.size();
  vector<double> x(n, 0.0);
  int count = 0;

  while (true) {
    vector<double> new_x = x;

    for (int i = 0; i < n; ++i) {
      double sum1 = 0.0;
      for (int j = 0; j < i; ++j) {
        sum1 += A[i][j] * new_x[j];
      }

      double sum2 = 0.0;
      for (int j = i + 1; j < n; ++j) {
        sum2 += A[i][j] * x[j];
      }

      new_x[i] = (b[i] - sum1 - sum2) / A[i][i];
    }

    double error = 0.0;
    for (int i = 0; i < n; ++i) {
      error = max(error, abs(new_x[i] - x[i]));
      x[i] = new_x[i];
    }
    count++;

    if (error < EPSILON) {
      break;
    }
  }

  return make_pair(x, count);
}



int main() {
  vector<vector<double>> A = {
    {0.86, -0.02, -0.13, -0.15},
    {-0.02, 0.95, -0.04, 0.48},
    {-0.13, -0.04, 0.79, -0.09},
    {-0.15, 0.48, -0.09, 0.81}};
  vector<double> b = {0.84, 0.09, 1.23, 0.75};
  
  auto resultSimpleIteration = simpleIterationMethod(A, b);
  auto resultGaussSeidel = gaussSeidelMethod(A, b);

  cout << "Method of simple iterations:" << endl;
  cout << "Solution:" << endl;
  for (double value : resultSimpleIteration.first){
    cout << value << endl;
  } 
  cout << "Iterations: " << resultSimpleIteration.second << endl;
    
  cout << "Gauss-Seidel method:" << endl;
  cout << "Solution: "<< endl;
  for (double value : resultGaussSeidel.first){
    cout << value << endl;
  } 
  cout << "Iterations: " << resultGaussSeidel.second << endl;


  return 0;
}

/*
expected:
x1 = 1.589 (rounded)
x2 = -0.736 (rounded)
x3 = 1.995 (rounded)
x4 = 1.878 (rounded)

received
X1 = 1.58885
X2 = -0.736978
X3 = 1.99512
X4 = 1.87856
*/