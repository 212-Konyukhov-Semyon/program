#include "includes.h"
Brevno::Brevno(double x1,double y1,double x2,double y2,double r) {
	this->x1=x1;
	this->y1=y1;
	this->x2=x2;
	this->y2=y2;
	this->r=r;
}
double Brevno::cyl(double x0,double y0) {
	double k=y2-y1;
	double b=x1-x2;
	double c=k*k+b*b;
	double var1=(-y1*b-x1*k);
	double var2=b*(x1+x2)/2-k*(y1+y2)/ 2;
	double d1=abs(k*x0+b*y0+var1)/sqrt(c);
	double d2=abs(-b*x0+k*y0+var2)/sqrt(c);
	if (r*r>d1*d1 && c/4>d2*d2) {
		return sqrt(r*r-d1*d1);
	}
	return 0;
}
