#include<iostream>
#define ll long long int
using namespace std;
ll arr[100]={0,};
ll fib(int n){
    if(n<1) return 0;
    if(arr[n]==0){
        arr[n]=fib(n-1)+fib(n-2);
    }
    return arr[n];
}
int main(){ //2748
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    arr[1]=1;
    cout<<fib(N)<<'\n';
}