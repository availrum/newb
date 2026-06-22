#include<iostream>
#include<vector>
#define ll long long int
using namespace std;
const ll divid=1000000007;
ll rec(ll n, ll num){
    if(num==0) return 1;
    else if(num==1) return n%divid;
    ll tmp=rec(n,num/2)%divid;
    tmp=(tmp*tmp)%divid;
    if(num%2!=0) tmp=((tmp%divid)*(n%divid))%divid;
    return tmp;
}
int main(){ //9343
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    vector<ll> fac(2000001,1);
    for(int i=2; i<2000001; ++i) fac[i]=((fac[i-1]%divid)*i)%divid;
    for(int tcase=0; tcase<T; ++tcase){
        ll N,t;
        cin>>N;
        ll sol=(fac[2*N]*rec((fac[N]*fac[N])%divid, divid-2) )%divid;
        sol=(sol*rec(N+1,divid-2))%divid;
        // cout<<fac[2*N]<<'\n';
        cout<<sol<<'\n';
        //nCr = n!/((n-r)!r!) => n! ((N-r)!)
        // (2N)!/(N!N!) , (N/N+1)*(2N)!/((N)!(N)!)
    }
}