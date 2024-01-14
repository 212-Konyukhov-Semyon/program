#include "includes.h"
using namespace std;
Rover::Rover(int head,int clirence,double alpha,double beta,int sp,Pole& pol)
{
    this->head=head;
    this->clirence=clirence;
    this->alpha=alpha;
    this->beta=beta;
    this->sp=sp;
    this->pol=pol;

}
Rover::Rover(){
    head=0;
    clirence=0;
    alpha=0;
    beta=0;
    sp=0;
}
int Rover::sens(int x0,int y0,int x,int y)
{
    int i,j;
    int dx=(0<x-x0)-(0>x-x0);
    int dy=(0<y-y0)-(0>y-y0);
    if(dy==0){
        for(i=x0;i<=x;i+=dx){
            if (pol.Mas[i+dx][y]-pol.Mas[i][y]>clirence){
                return 0;
            }
            if (pol.Mas[i+dx][y-1]-pol.Mas[i][y-1]>clirence){
                return 0;
            }
            if (pol.Mas[i+dx][y+1]-pol.Mas[i][y+1]>clirence){
                return 0;
            }
        }
    }
    if(dx==0){
        for(j=y0;j<=y;j+=dy){
            if (pol.Mas[x][j+dy]-pol.Mas[x][j]>clirence){
                return 0;
            }
            if (pol.Mas[x-1][j+dy]-pol.Mas[x-1][j]>clirence){
                return 0;
            }
            if (pol.Mas[x+1][j+dy]-pol.Mas[x+1][j]>clirence){
                return 0;
            }
        }
    }
    if(dx!=0 && dy!=0){
        for(i=x0;i<=x;i+=dx){
            for(j=x0;j<=x;j+=dx){
                if (pol.Mas[i-dx][j]-pol.Mas[i][j+dy]>clirence){
                    return 0;
                }
                if (pol.Mas[i][j]-pol.Mas[i+dx][j+dy]>clirence){
                    return 0;
                }
                if (pol.Mas[i][j-dy]-pol.Mas[i+dx][j]>clirence){
                    return 0;
                }
            }
        }
    }
    return 1;
}
int Rover::ugol(int x0,int y0,int x,int y){
    int i,j;
    int dx=(0<x-x0)-(0>x-x0);
    int dy=(0<y-y0)-(0>y-y0);
    if(dx!=0 && dy!=0){
        for(i=x0;i<=x;i+=dx){
            for(j=x0;j<=x;j+=dx){
                if (abs(pol.Mas[i][j]-pol.Mas[i+dx][j+dy])>alpha){
                    return 0;
                }
                if (abs(pol.Mas[i][j]-pol.Mas[i-dx][j-dy])>alpha){
                    return 0;
                }
                if (abs(pol.Mas[i][j]-pol.Mas[i+dx][j-dy])>beta){
                    return 0;
                }
                if (abs(pol.Mas[i][j]-pol.Mas[i-dx][j+dy])>beta){
                    return 0;
                }
            }
        }
    }
    if(dy==0){
         for(i=x0;i<=x;i+=dx){
            if (abs(pol.Mas[i][y]-pol.Mas[i+dx][y])>alpha){
                return 0;
            }
            if (abs(pol.Mas[i][y]-pol.Mas[i-dx][y])>alpha){
                return 0;
            }
            if (abs(pol.Mas[i][y]-pol.Mas[i][y+1])>beta){
                return 0;
            }
            if (abs(pol.Mas[i][y]-pol.Mas[i][y-1])>beta){
                return 0;
            }
        }
    }
    if(dx==0){
         for(j=y0;j<=y;j+=dy){
            if (abs(pol.Mas[x][j]-pol.Mas[x][j+dy])>alpha){
                return 0;
            }
            if (abs(pol.Mas[x][j]-pol.Mas[x][j-dy])>alpha){
                return 0;
            }
            if (abs(pol.Mas[x][j]-pol.Mas[x+1][j])>beta){
                return 0;
            }
            if (abs(pol.Mas[x][j]-pol.Mas[x-1][j])>beta){
                return 0;
            }
        }
    }
    return 1;
}
