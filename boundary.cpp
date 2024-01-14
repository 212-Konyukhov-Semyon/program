#include "includes.h"
Boundary::Boundary(string mes, string logbound, string logcont,int time,int data) {
	this->mes = mes;
	this->logbound = logbound;
	this->con = Control(logcont,time,data);
	this->time=time;
	this->data=data;
}
void Boundary::cons_read()
{
    string str,line;
    double x,y,alpha,beta;
    int ch,cs,cb,head,clirence,sp,S1,F1,S2,F2;
    ofstream logbound(this->logbound);
    ifstream mes(this->mes);
    while(getline(mes,line)){
        istringstream iss(line);
        iss >>str;
        if(str=="pole"){
            iss >> x;
            iss >> y;
            logbound << "otpravil razmery" << endl;
        }
        if(str=="gener"){
            iss >> ch;
            iss >> cs;
            iss >> cb;
            logbound << "otpravil kolichestvo kochek" << endl;
        }
        if(str=="pr"){
            logbound << "otpravil pole na pechat' " << endl;
        }
        if(str=="rover"){
            iss >> head;
            iss >> clirence;
            iss >> alpha;
            iss >> beta;
            iss >> sp;
            logbound << "otpravil rover" << endl;
        }
        if(str=="processor"){
            iss>>S1;
            iss>>S2;
            iss>>F1;
            iss>>F2;
            logbound << "otpravil processor"<<endl;
        }
    }
    con.f(x,y,ch,cs,cb,head,clirence,alpha,beta,sp,S1,S2,F1,F2);
}
