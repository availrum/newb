#include<iostream>
#include<vector>
#define ll long long int
using namespace std;
ll like_fib(ll n, vector<ll>& arr){
    if(arr[n]) return arr[n];
    return arr[n]=like_fib(n-1,arr)+like_fib(n-3,arr);
}
int main(){ //11495
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N;
    cin>>N;
    vector<ll> arr(N+4);
    arr[1]=1;
    arr[2]=1;
    arr[3]=1;
    cout<<like_fib(N,arr)<<'\n';
}