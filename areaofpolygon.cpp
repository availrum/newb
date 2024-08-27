#include<iostream>
#include<cmath>
using namespace std;
int main(){//2166
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    long double cx=0,cy=0;
    long double arrx[N+1], arry[N+1];
    for(int i=0; i<N; ++i) cin>>arrx[i]>>arry[i];
    long double sum=0;
    for(int i=0; i<N; ++i){
        if(i!=0) sum+=0.5*(arrx[i-1]*arry[i]-arrx[i]*arry[i-1]);
        else sum+=0.5*(arrx[N-1]*arry[i]-arrx[i]*arry[N-1]);
    }
    sum=abs(sum);
    cout.precision(1);
    cout<<fixed;
    cout<<sum<<'\n';
}