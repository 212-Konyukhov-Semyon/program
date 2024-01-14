#include "includes.h"
Kamen::Kamen(double x,double y,double r) {
	this->x=x;
	this->y=y;
	this->r=r;
}
double Kamen::dist(double x0,double y0) {
	if (r*r-(x-x0)*(x-x0)-(y-y0)*(y-y0)>0) {
		return sqrt(r*r-(x-x0)*(x-x0)-(y-y0)*(y-y0));
	}
	return 0;
}
