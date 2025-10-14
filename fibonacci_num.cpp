#include<iostream>
#define ll long long int
using namespace std;
ll num[46]={0,};
ll fib(int n){
    if(num[n] || n==0) return num[n];
    return num[n]=fib(n-1)+fib(n-2);
}
int main(){ //2747
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    num[1]=1;
    cout<<fib(N)<<'\n';
}