#ifndef ROVER_H_INCLUDED
#define ROVER_H_INCLUDED
#include "includes.h"
using namespace std;
class Pole;
class Rover
{
private:
    int clirence;
    double alpha;
    double beta;
    int head;
    int sp;
public:
    Pole pol;
    Rover(int head,int clirence,double alpha,double beta,int sp,Pole& pol);
    Rover();
    int sens(int x0,int y0,int x,int y);
    int ugol(int x0,int y0,int x,int y);
};


#endif // ROVER_H_INCLUDED
