#include<iostream>
#include<cmath>
using namespace std;
int main(){//9206
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,idx=0;
    long double coef[5],V,x=0.0000000001,cal=1,smalh=0.0001,tmps,tmpe,sta,en,sol;
    cin>>V>>N;
    sol=100001;
    for(int i=0; i<N; ++i){
        x=0.0000000001;
        cal=0;
        for(int j=0; j<3; ++j) cin>>coef[j];
        while(x<=coef[2]){
            sta=x;
            tmps=(coef[0]*exp(-x*x)+coef[1]*sqrt(x))*(coef[0]*exp(-x*x)+coef[1]*sqrt(x))*M_PI;
            x+=smalh;
            tmpe=(coef[0]*exp(-x*x)+coef[1]*sqrt(x))*(coef[0]*exp(-x*x)+coef[1]*sqrt(x))*M_PI;
            en=x;
            cal+=(smalh/6)*(tmps+tmpe+4*(coef[0]*exp(-((sta+en)/2)*((sta+en)/2))+coef[1]*sqrt(((sta+en)/2)))*(coef[0]*exp(-((sta+en)/2)*((sta+en)/2))+coef[1]*sqrt(((sta+en)/2)))*M_PI);
        }
        if(abs(V-cal)<abs(sol)){
            idx=i;
            sol=abs(V-cal);
        }
    }
    cout<<idx<<'\n';
}