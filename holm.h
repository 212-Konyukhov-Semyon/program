#ifndef HOLM_H_INCLUDED
#define HOLM_H_INCLUDED
#include "includes.h"
using namespace std;
class Holm
{
private:
    double x;
    double y;
    double sigx;
    double sigy;
    double sigxy;
    double high;
public:
    Holm()=default;
    Holm(double x, double y, double sigx, double sigy, double high);
    double Gauss(double x0,double y0);
};


#endif // HOLM_H_INCLUDED
