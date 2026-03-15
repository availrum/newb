#include<iostream>
#include<vector>
#define ll long long int
using namespace std;
ll rec(ll n, vector<ll>& vec){
    if(vec[n]) return vec[n];
    ll num1=rec(n-1,vec);
    ll num2=rec(n-2,vec);
    return vec[n]=num1+num2;
}
int main(){ //13301
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N,t;
    cin>>N;
    vector<ll> vec(N+2,0);
    vec[0]=1;
    vec[1]=1;
    ll sol=2*rec(N+1,vec);
    cout<<sol<<'\n';
}