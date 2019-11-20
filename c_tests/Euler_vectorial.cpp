#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

const double K=50.0;
void euler(double t_init,double t_final,double h, std::vector<double> & y);
double f(double t, const std::vector<double> & y, int id);
int main(void)
{
  //const double N=2;
  const double T_init=0;
  const double T_final=17.0;
  const double dT=0.01;
  std::vector<double> y = {1,0}; //{x0,y0}
  euler(T_init,T_final,dT,y);
  return 0;
}

void euler(double t_init,double t_final,double h, std::vector<double> & y)
{
  const int N= (t_final-t_init)/h;
  std::vector<double> yaux(y.size());
  for (int nt = 0; nt< N ; ++nt)
    {
      double t = t_init + h*nt;
      std::copy(y.begin(),y.end(), yaux.begin());
      // Evolucionamos cada componente
      //Para este caso serian solo 2 componentes x,v
      for(int id =0; id< y.size() ; ++id) 
	{
	  y[id] = y[id] + h*f(t,yaux,id);
	}
      std::cout <<t <<"\t" << y[0] <<"\t"<<y[1]<<std::endl;
    }
}
double f(double t, const std::vector<double> & y, int id)
{
  if (0 == id)
    {
      return y[1];
    }
  else if (1 == id)
    {
      return -K*y[0];
    }
  else
    {
      std::cerr<<"ERROR!!! Id does not exist --> "<<id<<std::endl;
      exit(1);
    }
}
