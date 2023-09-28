#include <iostream>
#include <fstream>
#include <math.h>
#include <random>
#include <time.h>
#include <vector>
class Holm
{
private:
    double x;
    double y;
    double sig;
    double high;
public:
    Holm(double razm_x,double razm_y);
    Holm(double x0,double y0,double sig0,double high0):
        x(x0),y(y0),high(high0){sig=abs(sig0);}
    double Gauss(double x0,double y0)const;
};
class Kamen
{
private:
    double x;
    double y;
    double r;
public:
    Kamen(double razm_x,double razm_y);
    Kamen(double x0,double y0,double r0): x(x0),y(y0),r(r0){}
    double get_r() const {return r;}
    double get_x() const {return x;}
    double get_y() const {return y;}
    double dist(double x0,double y0)const;
};
class Pole
{
private:
    double razm_x;
    double razm_y;
    std::vector<Holm> holms;
    std::vector<Kamen> kamens;
    int ch;
    int cs;
public:
    Pole()= default;
    Pole(double x,double y,int ch=0,int cs=0);
    void pr(std::ofstream &file1,std::ofstream &file2) const;
};
double f(double x, double y, Holm H);
int main()
{
    srand(time(NULL));
    Pole kochka(20,20,20,10);
    std::ofstream file1("1.txt");
    std::ofstream file2("2.txt");
    kochka.pr(file1,file2);
    file1.close();
    file2.close();
    return 0;
}
Holm::Holm(double razm_x,double razm_y)
{
    x=rand()/double(RAND_MAX)*razm_x/2-razm_x/2;
    y=rand()/double(RAND_MAX)*razm_y/2-razm_y/2;
    sig=rand()/double(RAND_MAX)*2+0.1;
    high=rand()/double(RAND_MAX)*5-3;
};
Kamen::Kamen(double razm_x,double razm_y)
{
    x=rand()/double(RAND_MAX)*razm_x-razm_x/2;
    y=rand()/double(RAND_MAX)*razm_y-razm_y/2;
    r=rand()/double(RAND_MAX)*1+0.5;
}
Pole::Pole(double x,double y,int ch,int cs):razm_x(x),razm_y(y),ch(ch),cs(cs)
{
    for(int i = 0; i<ch;i++){
        holms.push_back(Holm(x,y));
    }
    for(int i = 0; i<cs;i++){
        kamens.push_back(Kamen(x,y));
    }
}

double Holm::Gauss(double x0,double y0)const
{
    double r = exp(-((x-x0)*(x-x0)+(y-y0)*(y-y0))/2*sig*sig);
    return (high *r)/(sig*sqrt(2*M_PI));
}
void Pole::pr(std::ofstream &file1,std::ofstream &file2)const
{
    double z,h;
    for (double i = -razm_x/2;i<= razm_x/2;i+=razm_x/40){
        for(double j = -razm_y/2;j<=razm_y/2;j+=razm_y/40){
            z=0;
            for (int k = 0;k<ch;k++){
                z+=holms[k].Gauss(i,j);
            }
            file1 <<i << " " << j << " " << z << "\n";
        }
        file1 << "\n";
    }
    for(int k=0;k<cs;k++){
        for(double i=kamens[k].get_r();i>0;i-=kamens[k].get_r()/5){
            for(double j=0;j<=2;j+=0.1){
                file2<<kamens[k].get_x()+i*cos(j*M_PI)<< " " << kamens[k].get_y()+i*sin(j*M_PI) << " "<< sqrt(kamens[k].get_r()*kamens[k].get_r()-i*i) << "\n";
            }
            file2 <<"\n";
        }
        file2 << "\n";
    }
}
