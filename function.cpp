#include<iostream>
#define ll long long int
using namespace std;
// ll divid=1000000007;
ll rec(ll n, ll num, ll divid){
    if(num==0) return 1;
    else if(n%divid==0) return 0;
    else if(num==1) return n%divid;
    ll tmp=rec(n,num/2,divid);
    if(tmp>divid) tmp%=divid;
    tmp=((tmp)*(tmp));
    if(tmp>divid) tmp%=divid;
    if(num%2!=0) tmp=((tmp)*(n));
    if(tmp>divid) tmp%=divid;
    return tmp%divid;
}
int main(){ //24059
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    ll arr[n+1], sol;
    for(int i=0; i<=n; ++i){
        cin>>arr[i];
    }
    ll divid;
    cin>>divid;
    //a^(p)=a (mod p);
    //a^(p-1+2)=a^2
    //a^(p-1+p-1+2)=a^2
    //a^(p+p+p-1)=a^2
    //a^(n%(p-1))
    //a2^(a1^(a0))
    //a2^((a1^(a0))%(m-1))
    //a1^(a0) %(m-1)
    for(int i=0; i<=n; ++i){
        if(i==0) sol=arr[i];
        else if(i!=n){
            sol=rec(arr[i],sol, divid-1);
            //지수에 들어가는 용도면 p-1로 나눠야 같은값이 나옴
            // cout<<sol<<'\n';
        }
        else sol=rec(arr[i],sol,divid);
    }
    if(arr[n]%divid==0) sol=0;
    else sol%=divid;
    cout<<sol<<'\n';
}