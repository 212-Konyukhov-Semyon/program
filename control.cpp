#include "includes.h"
Control::Control(){
    data=0;
    time=0;
    A=new Pole();
    R=new Rover();
    P=new processor();
}
Control::Control(string logcont,int time,int data)
{
    this->logcont=logcont;
    this->time=time;
    this->data=data;
    A=new Pole();
    R=new Rover();
    P=new processor();
}

void Control::f(double x,double y, int ch,int cs,int cb,int head,int clirence,double alpha,double beta,int sp,int S1,int S2,int F1,int F2)
{
    ofstream logcont(this->logcont);
    logcont<< "Poluchil Razmery polya"<< endl;
    A=new Pole(x,y);
    logcont<< "Poluchil kolichestvo kochek"<< endl;
    (*A).gener(ch,cs,cb);
    logcont<< "Pole gotovo k raspechatki"<< endl;
    (*A).pr();
    logcont<<"Poluchil parametry rovera"<<endl;
    R=new Rover(head,clirence,alpha,beta,sp,*A);
    logcont<< "Marshryt mozhet byt' postroen"<< endl;
    P=new processor(S1,S2,F1,F2,*R);
    (*P).dvizh();
    delete A;
    delete R;
    delete P;
}
