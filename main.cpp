#include "includes.h"

using namespace std;

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
        Boundary *V=new Boundary(mes,logbound,logcont,time,data);
        (*V).cons_read();
        delete V;
    }
    return 0;
}
