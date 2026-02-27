#include<iostream>
#define ll long long int
using namespace std;
const ll divid=1000000007;
ll rec(ll num, ll remain){
    if(remain==1) return num;
    ll tmp=rec(num,remain/2);
    tmp=(tmp%divid*tmp%divid)%divid;
    if(remain%2==1) tmp=((tmp%divid)*(num))%divid;
    // cout<<tmp<<'\n';
    return tmp;
}
int main(){ //16134
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N,R;
    cin>>N>>R;
    //nCr=n!/(r!*(n-r)!)
    //a^(p-2)=1/a
    ll tmp=1, und=1;
    for(ll i=2; i<=N; ++i){
        tmp=((tmp%divid)*i)%divid;
        if(i==R || i==N-R){
            und=((und%divid)*tmp)%divid;
            if(R==N-R) und=((und%divid)*tmp)%divid;
        }
    }
    ll sol=((tmp%divid)*(rec(und,divid-2)%divid))%divid;
    cout<<sol<<'\n';
}