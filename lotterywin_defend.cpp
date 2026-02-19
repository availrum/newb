#include<iostream>
#define ll long long int
using namespace std;
ll rec(ll num, ll remain, ll divid){
    if(remain==1) return num;
    ll tmp=rec(num,remain/2,divid);
    tmp=(tmp%divid*tmp%divid)%divid;
    if(remain%2==1) tmp=((tmp%divid)*(num))%divid;
    // cout<<tmp<<'\n';
    return tmp;
}
int main(){ //20412
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll m,seed,x1,x2;
    cin>>m>>seed>>x1>>x2;
    // a^(p) %p === a %p

    // x1 = (a*seed +c) %m
    //x2 = (a*x1 +c) %m
    //x1-x2=(a*seed+c) %m - (a*x1+c)%m
    //x1-x2=((a*seed)%m +c%m) - ((a*x1)%m +c%m)
    //     = (a%m*seed%m)%m-(a%m*x1%m)%m 인데 m이 가장 크므로
    //     = (a*seed)%m-(a*x1)%m
    //     = (a*seed-a*x1)%m
    // (x1-x2)*(seed-x1)^(m-2) = a

    ll a=((x1-x2+m)%m*rec((seed-x1+m),m-2,m))%m;
    ll c=(x1-(a*seed+m)%m+m)%m;
    if(seed==x1) cout<<"0 "<<x1%m<<"\n";
    else cout<<a<<' '<<c<<'\n';
}