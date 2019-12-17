// RK4
#include <iostream>
#include <cmath>
using namespace std;

// variable constantes globales
const double K = 100;
const double M = 2;
const double LAMBDA = 0.5;
const double DeltaT = 0.01;

// declaracion de funciones
double f0(double t, double y0, double y1); // derivada de y0
double f1(double t, double y0, double y1); // derivada de y1
void rk4(double t, double h, double & y0, double & y1); // metodo de runge kutta 4 orden

int main(void)
{
  double x, v, time;
  x = 1;
  v = 0;
  for(time = 0; time <= 10; time += DeltaT) {
    cout << time << "\t" << x << "\t" << v << endl;
    rk4(time, DeltaT, x, v);
  }


  return 0;
}

double f0(double t, double y0, double y1)
{
  return y1;
}

double f1(double t, double y0, double y1)
{
  return (-K/M)*pow(y0, LAMBDA);
}

void rk4(double t, double h, double & y0, double & y1) // metodo de runge kutta 4 orden
{
  double k10, k11, k20, k21, k30, k31, k40, k41;
  k10 = h*f0(t, y0, y1);
  k11 = h*f1(t, y0, y1);
  k20 = h*f0(t+h/2, y0 + k10/2, y1 + k11/2);
  k21 = h*f1(t+h/2, y0 + k10/2, y1 + k11/2);
  k30 = h*f0(t+h/2, y0 + k20/2, y1 + k21/2);
  k31 = h*f1(t+h/2, y0 + k20/2, y1 + k21/2);
  k40 = h*f0(t + h, y0 + k30, y1 + k31);
  k41 = h*f1(t + h, y0 + k30, y1 + k31);

  y0 = y0 + (1.0/6.0)*(k10 + 2*k20 + 2*k30 + k40);
  y1 = y1 + (1.0/6.0)*(k11 + 2*k21 + 2*k31 + k41);
}
