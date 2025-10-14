#include<iostream>
#define ll long long int
using namespace std;
ll num[n]={0,};
ll fib(int n){
    if(num[n] || n==0) return num[n];
    return fib(num[n-1])+fib(num[n-2]);
}
int main(){ //
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    num[1]=1;
    cout<<fib(N)<<'\n';
}