#include "quadratic_equation.h"

double *solve_equation(double a, double b, double c) {
  double x, D;
  static double res[2];
  res[0] = 0.0;
  res[1] = 0.0;
  D = pow(b, 2) - 4 * a * c;
  x = (-b - sqrt(D)) / (2 * a);
  res[0] = x;
  x = (-b + sqrt(D)) / (2 * a);
  res[1] = x;
  return res;
}
