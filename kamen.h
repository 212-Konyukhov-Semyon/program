#ifndef KAMEN_H_INCLUDED
#define KAMEN_H_INCLUDED
#include "includes.h"
using namespace std;
class Kamen
{
private:
    double x;
    double y;
    double r;
public:
    Kamen()=default;
    Kamen(double x, double y, double r);
    double dist(double x0,double y0);
};


#endif // KAMEN_H_INCLUDED
