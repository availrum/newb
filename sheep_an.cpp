#include<iostream>
#define ll long long int
using namespace std;
const int divid=1000000007;
// const int divid=17;
ll rec(ll num, ll remain){
    if(remain==1) return num;
    ll tmp=rec(num,remain/2);
    tmp=(tmp%divid*tmp%divid)%divid;
    if(remain%2==1) tmp=((tmp%divid)*(num))%divid;
    // cout<<tmp<<'\n';
    return tmp;
}
int main(){ //30413
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll A,B;
    cin>>A>>B;
    // a^(p-2) %p === 1/a %p
    // a^(p-1) %p === 1 %p
    // a^(p) %p === a %p
    // a^(p+1) %p === a^2 %p
    // a^(p+2) %p === a^3 %p
    // ...
    // a^(p+B) %p === a^B %p
    // 1+a+a^2+...+a^(b-1) = (a^(b)-1)/(a-1)
    // (a^(b)-1)/(a-1) %p == ((a^(b)-1)%divid  * (a-1)^(divid-2)%divid)%divid
    ll sol;
    if(A!=1) sol=( ((rec(A,B)-1)%divid) * (rec(A-1,divid-2)%divid) )%divid;
    else sol=B%divid;
    cout<<sol<<'\n';
}