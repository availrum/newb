#include<iostream>
#include<vector>
#define ll long long int
using namespace std;
ll koong(ll n, vector<ll>& val){
    if(val[n]) return val[n];
    return val[n]=koong(n-1,val)+val[n-2]+val[n-3]+val[n-4];
}
int main(){ //9507
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    vector<ll> val(68,0);
    val[0]=1;
    val[1]=1;
    val[2]=2;
    val[3]=4;
    for(int tcase=0; tcase<t; ++tcase){
        ll N;
        cin>>N;
        cout<<koong(N,val)<<'\n';
    }
}