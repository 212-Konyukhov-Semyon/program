#include "includes.h"
Pole::Pole(){
    x=0;
    y=0;
    Mas[0][0]=0;
}
Pole::Pole(double x,double y) {
	this->x=x;
	this->y=y;
	Mas[0][0]=0;
}
void Pole::gener(int ch,int cs,int cb)
{
    double x,y,sigx, sigy, high,r,x2,y2;
    for(int i = 0; i<ch;i++){
        x=double(rand()%10000)/10000 * this->x;
        y=double(rand()%10000)/10000 * this->y;
        sigx=double(rand()%10000)/10000+0.1;
        sigy=double(rand()%10000)/10000+0.1;
        high=(double(rand()%10000)/10000-0.3) * sqrt(this->x*this->y);
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
		r = double(rand() % 10000) / 20000 + 0.1;
        brevns.push_back(Brevno(x,y,x2,y2,r));
    }
}


void Pole::pr()
{
    int k;
	double h;
	ofstream file1("1.txt");
    for (int i =0;i<128;i++) {
        for (int j=0;j<128;j++) {
            double x=i* this->x /128;
            double y=j* this->y /128;
            h = 0;
            for (k = 0; k < holms.size(); k++) {
                h += holms[k].Gauss(x,y);
            }
            for (k = 0; k < kamens.size(); k++) {
                h += kamens[k].dist(x,y);
            }
            for (k = 0; k < brevns.size(); k++) {
                h += brevns[k].cyl(x,y);
            }
            file1<< x << " " << y << " " << h <<endl;
            Mas[i][j]=128*h/sqrt(this->x*this->y);
        }
        file1<<endl;
	}
}
