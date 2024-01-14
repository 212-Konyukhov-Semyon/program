#ifndef BOUNDARY_H_INCLUDED
#define BOUNDARY_H_INCLUDED
#include "includes.h"
using namespace std;
class Boundary
{
private:
    string mes;
    string logbound;
    Control con;
    int time;
    int data;
public:
    Boundary(string mes,string logbound,string logcont,int time,int data);
    void cons_read();
};
#endif // BOUNDARY_H_INCLUDED
