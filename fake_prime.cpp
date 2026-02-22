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
bool isprime(ll num){
    for(int i=2; i*i<=num; ++i){
        if(num%i==0) return false;
    }
    return true;
}
int main(){ //4233
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll p,a;
    while(cin>>p>>a){
        if(p==0 && a==0) return 0;
        if(isprime(p)){
            cout<<"no\n";
            continue;
        }
        else if(rec(a,p,p)==a) cout<<"yes\n";
        else cout<<"no\n";
    }
}