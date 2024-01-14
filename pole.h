#ifndef POLE_H_INCLUDED
#define POLE_H_INCLUDED
#include "includes.h"
using namespace std;
class Pole
{
private:
    double x;
    double y;
public:
    int Mas[128][128];
    vector<Holm> holms;
    vector<Kamen> kamens;
    vector<Brevno> brevns;
    /*int ch;
    int cs;
    int cb;*/
    Pole();
    Pole(double x,double y);
    void gener(int ch,int cs,int cb);
    void pr();
};


#endif // POLE_H_INCLUDED
