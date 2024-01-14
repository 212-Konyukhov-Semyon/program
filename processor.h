#ifndef PROCESSOR_H_INCLUDED
#define PROCESSOR_H_INCLUDED
#include "includes.h"
using namespace std;
class processor{
private:
    int S1;
    int S2;
    int F1;
    int F2;
    Rover R;
public:
    processor(int S1,int S2,int F1,int F2,Rover&R);
    processor();
    void dvizh();
};
#endif // PROCESSOR_H_INCLUDED
