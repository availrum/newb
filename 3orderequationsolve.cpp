#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){//9735
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    int soli;
    long double sold[4];
    long double coef[5],x[4],sol[4],cal=1,calp=0,tmp=1;
    cin>>N;
    x[0]=-999999.99999;
    x[1]=0;
    x[2]=999999.99999;
    // x[2]=0.1;
    for(int k=0; k<N; k++){
        for(int i=3; i>=0; --i) cin>>coef[i];
        x[1]=-1*coef[2]/(3.*coef[3]);
        if(x[1]==0) x[1]=0.00001;
        for(int j=0; j<3; j++){//x의 초기값 변경
            sol[j]=x[j];
            cal=1.,calp=1.,tmp=1.;
            while(abs(cal/calp)>0.000001){
                cal=0;
                calp=0;
                tmp=1;
                for(int i=0; i<=3; ++i){
                    if(i==0) cal+=coef[i];
                    else cal+=coef[i]*tmp; //c+bx+ax^2+...
                    tmp*=sol[j];
                }
                tmp=1;
                for(int i=1; i<=3; ++i){
                    if(i==1) calp+=coef[i];
                    else calp+=i*tmp*coef[i]; //b+2ax+3mx^2...
                    tmp*=sol[j];
                }
                // cout<<cal<<' '<<calp<<' '<<sol[j]<<'\n';
                sol[j]-=cal/calp;
            }
            // cout<<' '<<'\n';
            // sol=x*1000;
            // soli=round(10000*sol[j]);
            // sold[j]=0.0001*soli;
            sold[j]=sol[j];
            // if(j==0) cout<<sold[j]<<'\n';
            // if(j!=0 && sold[j]!=sold[j-1]) cout<<sold[j]<<'\n';
        }
        // sort(sold,sold+3);
        // cout.precision(-4);
        // cout<<fixed;
        for(int i=0; i<3; i++){
            if(i==0) cout<<sold[i]<<' ';
            else if(abs(sold[i]-sold[i-1])>=0.0001) cout<<sold[i]<<' ';
        }
        cout<<'\n';
    }
}