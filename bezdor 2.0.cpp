#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>
#include <random>
#include <time.h>
#include <vector>
using namespace std;
class Boundary
{
private:
    string mes;
    string logbound;
    string logcont;
public:
    Boundary(string mes,string logbound,string logcont);
    void cons_read();
};
class Control
{
private:
    string logcont;
public:
    Control(string logcont);
    void f(double x,double y, int ch,int cs,int cb);
};
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
class Pole
{
private:
    double x;
    double y;
    vector<Holm> holms;
    vector<Kamen> kamens;
    vector<Brevno> brevns;
    int ch;
    int cs;
    int cb;
public:
    Pole(double x,double y);
    void gener(int ch,int cs,int cb);
    void pr();
};
int main()
{
    string str, line, mes, logbound, logcont;
    int data,time;
    cout << "Hello! Please vvedite imya konfig faila: ";
    cin>>str;
    ifstream conf(str);
    while(getline(conf,line)){
        istringstream iss(line);
        iss>>str;
        if (str=="com_file"){
            iss>>str;
            if(str=="="){
                iss>>mes;
            }
        }
        if (str=="log_boundary"){
            iss>>str;
            if(str=="="){
                iss>>logbound;
            }
        }
        if (str=="log_control"){
            iss>>str;
            if(str=="="){
                iss>>logcont;
            }
        }
        if (str=="data"){
            iss>>str;
            if(str=="="){
                iss>>data;
            }
        }
        if (str=="time"){
            iss>>str;
            if(str=="="){
                iss>>time;
            }
        }
        Boundary V(mes,logbound,logcont);
        V.cons_read();
    }
    return 0;
}
Holm::Holm(double x, double y, double sigx, double sigy, double high) {
	srand(time(NULL));
	this->x=x;
	this->y=y;
	this->sigx=sigx;
	this->sigy=sigy;
	this->sigxy=double(rand()%10000)/20000*sigx*sigy;
	this->high=high;
}
double Holm::Gauss(double x0,double y0)
{
    double r=sigxy/(sigx*sigy);
	return high*exp(((x-x0)*(x-x0)/(sigx*sigx)+(y-y0)*(y-y0)/(sigy*sigy)-2*r*(x-x0)*(y-y0)/(sigx*sigy))/(2*r*r-2));
}
Pole::Pole(double x,double y) {
	this->x=x;
	this->y=y;
}
Kamen::Kamen(double x,double y,double r) {
	this->x=x;
	this->y=y;
	this->r=r;
}
double Kamen::dist(double x0,double y0) {
	if (r*r-(x-x0)*(x-x0)-(y-y0)*(y-y0)>0) {
		return sqrt(r*r-(x-x0)*(x-x0)-(y-y0)*(y-y0));
	}
	return 0;
}

Brevno::Brevno(double x1,double y1,double x2,double y2,double r) {
	this->x1=x1;
	this->y1=y1;
	this->x2=x2;
	this->y2=y2;
	this->r=r;
}
double Brevno::cyl(double x0,double y0) {
	double k=y2-y1;
	double b=x1-x2;
	double c=k*k+b*b;
	double var1=(-y1*b-x1*k);
	double var2=b*(x1+x2)/2-k*(y1+y2)/ 2;
	double d1=abs(k*x0+b*y0+var1)/sqrt(c);
	double d2=abs(-b*x0+k*y0+var2)/sqrt(c);
	if (r*r>d1*d1 && c/4>d2*d2) {
		return sqrt(r*r-d1*d1);
	}
	return 0;
}
void Pole::gener(int ch,int cs,int cb)
{
    double x,y,sigx, sigy, high,r,x2,y2;
    for(int i = 0; i<ch;i++){
        x=double(rand()%10000)/10000 * this->x;
        y=double(rand()%10000)/10000 * this->y;
        sigx=double(rand()%10000)/10000;
        sigy=double(rand()%10000)/10000;
        high=(double(rand()%10000)/10000-0.5) * sqrt(this->x*this->y);
        holms.push_back(Holm(x,y,sigx,sigy,high));
    }
    for(int i = 0; i<cs;i++){
        x=double(rand()%10000)/10000 * this->x;
        y=double(rand()%10000)/10000 * this->y;
        r=double(rand()%10000)/10000;
        kamens.push_back(Kamen(x,y,r));
    }
    for(int i = 0; i<cb;i++){
        x = double(rand() % 10000) / 10000 * this->x;
		y = double(rand() % 10000) / 10000 * this->y;
		x2 = double(rand() % 10000) / 10000 * this->x;
		y2 = double(rand() % 10000) / 10000 * this->y;
		r = double(rand() % 10000) / 10000 + 0.4;
        brevns.push_back(Brevno(x,y,x2,y2,r));
    }
}


void Pole::pr()
{
    int k;
	double h;
	ofstream file1("1.txt");
	for (double i =0.;i<=x;i+=x/90) {
		for (double j=0.;j<=y;j+=y/90) {
			h = 0;
			for (k = 0; k < holms.size(); k++) {
				h += holms[k].Gauss(i,j);
			}
			for (k = 0; k < kamens.size(); k++) {
				h += kamens[k].dist(i,j);
			}
			for (k = 0; k < brevns.size(); k++) {
				h += brevns[k].cyl(i,j);
			}
			file1<< i << " " << j << " " << h <<endl;
		}
		file1<<endl;
	}
}
Boundary::Boundary(string mes, string logbound, string logcont) {
	this->mes = mes;
	this->logbound = logbound;
	this->logcont = logcont;
}
void Boundary::cons_read()
{
    string str,line;
    double x,y;
	int ch,cs,cb;
    Control cont(logcont);
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
    }
    cont.f(x,y,ch,cs,cb);
}
Control::Control(string logcont)
{
    this->logcont=logcont;
}
void Control::f(double x,double y, int ch,int cs,int cb)
{
    ofstream logcont(this->logcont);
    logcont<< "Poluchil Razmery polya"<< endl;
    Pole pov(x,y);
    logcont<< "Poluchil kolichestvo kochek"<< endl;
    pov.gener(ch,cs,cb);
    logcont<< "Pole gotovo k raspechatki"<< endl;
    pov.pr();
}
