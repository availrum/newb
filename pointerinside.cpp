#include<iostream>
using namespace std;
int arr[22];
int sign[22];
int num,maxi,mini,maxf,minf;
void rec(int N, int p, int m, int mul, int divi){
    if(N==1){
        int cal=arr[0];
        for(int i=1; i<=num; ++i){
            if(sign[i-1]==1) cal+=arr[i];
            else if(sign[i-1]==2) cal-=arr[i];
            else if(sign[i-1]==3) cal*=arr[i];
            else if(sign[i-1]==4) cal/=arr[i];
        }
        if(maxf==0 || maxi<cal){
            maxi=cal;
            maxf=1;
        }
        if(minf==0 || mini>cal){
            mini=cal;
            minf=1;
        }
        return;
    } 
    if(p!=0){
        sign[num-N]=1;
        rec(N-1,p-1,m,mul,divi);
    }
    if(m!=0){
        sign[num-N]=2;
        rec(N-1,p,m-1,mul,divi);
    }
    if(mul!=0){
        sign[num-N]=3;
        rec(N-1,p,m,mul-1,divi);
    }
    if(divi!=0){
        sign[num-N]=4;
        rec(N-1,p,m,mul,divi-1);
    }
    return;
}
int main(){//14888
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,p,m,mul,divi;
    cin>>N;
    num=N;
    for(int i=0; i<N; ++i) cin>>arr[i];
    cin>>p>>m>>mul>>divi;
    rec(N,p,m,mul,divi);
    cout<<maxi<<'\n';
    cout<<mini<<'\n';
}