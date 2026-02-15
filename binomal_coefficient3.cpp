#include<iostream>
#include<vector>
#define ll long long int
using namespace std;
const ll divid=1000000007;
ll rec(ll num, ll remain){
    if(remain==1) return num;
    ll cur=rec(num,remain/2);
    if(remain%2==0) num=((cur)%divid*(cur)%divid)%divid;
    else num=(((cur)%divid*(cur)%divid)*num)%divid;
    return num;
}
int main(){ //11401
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N,K;
    cin>>N>>K;
    // n!/((n-k)!*(k)!)
    // (a^(div-1))%div == 1(%div)
    // (a^(div-2))%div == 1/a (%div)
    // n! * ((n-k)!*k!)^(div-2)
    vector<ll> fac_div(N+1);
    fac_div[0]=1;
    for(int i=1; i<=N; ++i){
        fac_div[i]=((fac_div[i-1])%divid*(i%divid))%divid;
    }
    ll tmp=(fac_div[N-K]*fac_div[K])%divid;
    ll sol=((fac_div[N])%divid * (rec(tmp,divid-2))%divid )%divid;
    // cout<<tmp<<' '<<sol<<'\n';
    // cout<<rec(4,5)<<'\n';
    cout<<sol<<'\n';
}