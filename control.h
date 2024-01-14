#ifndef CONTROL_H_INCLUDED
#define CONTROL_H_INCLUDED
#include "includes.h"
using namespace std;
class Pole;
class Rover;
class processor;
class Control
{
private:
    string logcont;
    int time;
    int data;
    Pole *A;
    Rover *R;
    processor *P;
public:
    Control();
    Control(string logcont,int time,int data);
    void f(double x,double y, int ch,int cs,int cb,int head,int clirence,double alpha,double beta,int sp,int S1,int S2,int F1,int F2);
};


#endif // CONTROL_H_INCLUDED
