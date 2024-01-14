#include "includes.h"
Holm::Holm(double x, double y, double sigx, double sigy, double high) {
	srand(time(NULL));
	this->x=x;
	this->y=y;
	this->sigx=sigx;
	this->sigy=sigy;
	this->sigxy=double(rand()%10000)/20000*sigx*sigy;
	this->high=high;
}
double Holm::Gauss(double x0,double y0)
{
    double r=sigxy/(sigx*sigy);
	return high*exp(((x-x0)*(x-x0)/(sigx*sigx)+(y-y0)*(y-y0)/(sigy*sigy)-2*r*(x-x0)*(y-y0)/(sigx*sigy))/(2*r*r-2));
}
