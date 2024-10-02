#include<iostream>
using namespace std;
int cntrec;
int cntdp;
int fib(int n){
    if(n==1 || n==2){
        ++cntrec;
        return 1;
    }
    else{
        return fib(n-1)+fib(n-2);
    }
}
int fibo[41];
int fibonacci(int n){
    if(n>=3){
        for(int i=3; i<=n; ++i){
            fibo[i]=fibo[i-1]+fibo[i-2];
            ++cntdp;
        }
    }
    return fibo[n];
}
int main(){//24416
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,t;
    cin>>N;
    fibo[1]=1;
    fibo[2]=1;
    fib(N);
    fibonacci(N);
    cout<<cntrec<<' '<<cntdp<<'\n';
}