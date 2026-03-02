#include<iostream>
#include<vector>
#define ll long long int
using namespace std;
const ll divid=1000000;
vector<ll> fib(ll n){
    if(n==1) return {1,1,1,0};
    vector<ll> cur=fib(n/2);
    vector<ll> tmp(4);
    // if(n==0)
    tmp[0]=((cur[0]*cur[0])%divid+(cur[1]*cur[2])%divid)%divid;
    tmp[1]=((cur[0]*cur[1])%divid+(cur[1]*cur[3])%divid)%divid;
    tmp[2]=((cur[2]*cur[0])%divid+(cur[3]*cur[2])%divid)%divid;
    tmp[3]=((cur[2]*cur[1])%divid+(cur[3]*cur[3])%divid)%divid;
    if(n%2==1){
        vector<ll> val(4);
        val[0]=((tmp[0])%divid+(tmp[1])%divid)%divid;
        val[1]=(tmp[0])%divid;
        val[2]=((tmp[2])%divid+(tmp[3])%divid)%divid;
        val[3]=(tmp[2])%divid;
        return val;
    }
    return tmp;
}
int main(){ //2749
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    vector<ll> arr(4);
    arr[0]=1;
    arr[1]=1;
    arr[2]=1;
    arr[3]=0;
    vector<ll> sol=fib(n);
    // cout<<sol[0]<<' '<<sol[1]<<' '<<sol[2]<<' '<<sol[3]<<'\n';
    cout<<sol[2]<<'\n';
}