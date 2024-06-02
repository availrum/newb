#include<iostream>
#include<cmath>
using namespace std;
int main(){//14786
    ios::sync_with_stdio(false);
    long double coef[5],x=0.0000000001,cal=1,calp=1;
    for(int i=0; i<3; ++i) cin>>coef[i];
    while(abs(cal/calp)>0.000000001){
        cal=0;
        calp=0;
        cal+=coef[0]*x+coef[1]*sin(x)-coef[2];
        calp+=coef[0]+coef[1]*cos(x);
        x-=cal/calp;
    }
    cout.precision(10);
    cout<<fixed;
    cout<<x<<'\n';
}