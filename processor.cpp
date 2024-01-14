#include "includes.h"
processor::processor(int S1,int S2,int F1,int F2,Rover&R){
    this->S1=S1;
    this->S2=S2;
    this->F1=F1;
    this->F2=F2;
    this->R=R;
}
processor::processor(){
    S1=0;
    S2=0;
    F1=0;
    F2=0;
}
void processor::dvizh(){
    ofstream Z("2.txt");
    int i,j,k,n,t;
    int l=126*126;
    int m=S1*125+S2;
    int s=F1*125+F2;
    vector<vector<int>> agg(l);
    vector<int> rast(l,l);
    vector<int> o(l,-1);
    rast[m]=0;
    queue<int> q;
    q.push(m);
    for(i=0;i<126;i++){
        for(j=0;j<126;j++){
            for(k=i-1;k<i+2;k++){
                for(n=j-1;n<j+2;n++){
                    if(k>0 && k<126 && n>0 && n<126 && !(k==i && n==j)){
                        if(R.sens(i,j,k,n) && R.ugol(i,j,k,n)){
                                t=125*i+j;
                                agg[t].push_back(125*k+n);
                        }
                    }
                }
            }
        }
    }
    while(!q.empty()){
        int c=q.front();
        q.pop();
        for(int e: agg[c]){
            if(rast[e]>rast[c]+1){
                o[e]=c;
                rast[e]=rast[c]+1;
                q.push(e);
            }
        }
    }
    if (rast[s]==l){
        cout<< "No chanses"<<endl;
    }
    vector <int> marsh;
    while(s!=-1){
        marsh.push_back(s);
        s=o[s];
    }
    for(i=marsh.size()-1;i>-1;i--){
        k=marsh[i]/125;
        n=marsh[i]%125;
        Z<< double(k*10)/128<<" "<<double(n*10)/128<<" "<<double(R.pol.Mas[k][n]*10)/128<<endl;
    }
}

