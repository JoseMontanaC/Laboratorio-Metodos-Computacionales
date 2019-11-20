#include <iostream>
#include <cmath>

const double K=50.0;
const double M = 2;
const double LAMBDA = 1;
const double DeltaT = 0.01;
double f0(double t, double y0, double y1); //Returns derivative of y0
double f1(double t, double y0, double y1); //Returns derivative of y1
void euler(double t_init,double t_final, double h, double & x, double & v);

int main(void)
{
  const double T_init=0;
  const double T_final=17.0;
  double x=1;
  double v=0;
  euler(T_init,T_final,DeltaT,x,v);
  return 0;
}

void euler(double t_init,double t_final, double h, double & x, double & v)
{
  const int N= (t_final-t_init)/h;
  
  for(int nt = 0 ;nt<N ; ++nt)
    {
      double t = t_init + h*nt;
      double old_x=x;
      double old_v=v;
      x = x + h * f0(t,old_x,old_v);
      v = v + h * f1(t,old_x,old_v);
      std::cout<<t<<"\t"<<x<<"\t"<<v<<std::endl;
    }
}
      
    
double f0(double t, double y0, double y1)
{
  return y1;
}

double f1(double t, double y0, double y1)
{
  return (-K/M)* std::pow (y0, LAMBDA);
}

