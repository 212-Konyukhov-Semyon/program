#ifndef BREVNO_H_INCLUDED
#define BREVNO_H_INCLUDED
#include "includes.h"
using namespace std;
class Brevno
{
private:
    double x1;
    double x2;
    double y1;
    double y2;
    double r;
public:
    Brevno()=default;
    Brevno(double x1, double y1, double x2, double y2, double r);
    double cyl(double x0,double y0);
};


#endif // BREVNO_H_INCLUDED
