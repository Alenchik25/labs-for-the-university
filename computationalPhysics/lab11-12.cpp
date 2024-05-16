#include <cmath>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

double func(double t, double x) { return t * x; }

double exactSolution(double t) { return exp(0.5 * pow(t, 2)); }

void modifiedEuler(double t0, double x0, double h, double &lastX, ofstream &outFile) {
  double x = x0;
  while (t0 < 2) {
    double k1 = h * func(t0, x);
    double k2 = h * func(t0 + h, x + k1);
    x = x + 0.5 * (k1 + k2);
    t0 += h;
    outFile << "Modified Euler method: x(" << t0 << ") = " << x << endl;
  }
  lastX = x;
}

void improvedEuler(double t0, double x0, double h, double &lastX, ofstream &outFile) {
  double x = x0;
  while (t0 < 2) {
    double k1 = h * func(t0, x);
    double k2 = h * func(t0 + h, x + k1);
    x = x + (k1 + k2) * 0.5;
    t0 += h;
    outFile << "Improved Euler method: x(" << t0 << ") = " << x << endl;
  }
  lastX = x;
}

void adamsMethod(double t0, double x0, double h, vector<double> &x, ofstream &outFile) {
  x.push_back(x0);
  while (t0 < 2) {
    x.push_back(x.back() + h / 2.0 * (3 * func(t0, x.back()) - func(t0 - h, x.size() > 1 ? x[x.size() - 2] : x.back())));
    t0 += h;
    outFile << "Adams method: x(" << t0 << ") = " << x.back() << endl;
  }
}

double calculateError(double x_true, double x_approx) { return abs(x_true - x_approx); }

int main() {
  ofstream outFile("results.txt");

  if (!outFile) {
    cerr << "Unable to open file";
    return 1;
  }

  double t0 = 1.0;     // initial time
  double x0 = exp(1);  // initial value
  double h = 0.1;      // step size

  double lastXModifiedEuler, lastXImprovedEuler;
  vector<double> xAdams;

  // Solve the differential equation using the modified Euler method
  modifiedEuler(t0, x0, h, lastXModifiedEuler, outFile);
  outFile << "========================\n";
  // Solve the differential equation using the improved Euler (Heun's) method
  improvedEuler(t0, x0, h, lastXImprovedEuler, outFile);
  outFile << "========================\n";
  // Solve the differential equation using the Adams method
  adamsMethod(t0, x0, h, xAdams, outFile);
  int steps = 10;
  double trueSolution = exactSolution(t0 + h * steps);
  outFile << "True solution at x(" << t0 + h * steps << ") = " << trueSolution << endl;
  outFile << "========================\n";

  double modifiedEulerError = calculateError(trueSolution, lastXModifiedEuler);
  double improvedEulerError = calculateError(trueSolution, lastXImprovedEuler);
  double adamsError = calculateError(trueSolution, xAdams.back());
  outFile << "ERRORS:\n";
  outFile << "Modified Euler method error: " << modifiedEulerError << endl;
  outFile << "Improved Euler method error: " << improvedEulerError << endl;
  outFile << "Adams method error: " << adamsError << endl;

  outFile.close();
  return 0;
}
