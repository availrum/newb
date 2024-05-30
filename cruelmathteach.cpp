#include<iostream>
using namespace std;
int main(){//6098
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int D;
    long double coef[12],cal=1,calp=0,x,tmp=1;
    int sol;
    cin>>D;
    for(int i=0; i<=D; ++i) cin>>coef[i];
    x=5.0;

    while(abs(cal)>0.0001){
        cal=0;
        calp=0;
        tmp=1;
        for(int i=0; i<=D; ++i){
            if(i==0) cal+=coef[i];
            else cal+=coef[i]*tmp; //c+bx+ax^2+...
            tmp*=x;
        }
        tmp=1;
        for(int i=1; i<=D; ++i){
            if(i==1) calp+=coef[i];
            else calp+=i*tmp*coef[i]; //b+2ax+3mx^2...
            tmp*=x;
        }
        cout<<cal<<' '<<calp<<' '<<x<<'\n';
        x-=cal/calp;
    }
    sol=x*1000;
    cout<<sol<<'\n';
}