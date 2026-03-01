#include<iostream>
#define ll long long int
using namespace std;
const ll divid=1000003LL;
ll rec(ll num, ll remain){
    if(remain==1) return num%divid;
    else if(remain==0) return 1;
    ll tmp=rec(num,remain/2)%divid;
    tmp=(tmp%divid*tmp%divid)%divid;
    if(remain%2==1) tmp=((tmp%divid)*(num%divid))%divid;
    return tmp%divid;
}
int main(){ //24731
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll K;
    cin>>K;
    //nCr=n!/(r!*(n-r)!)
    //a^(p-2)=1/a
    // 시작자리는 01 1, 그전엔 00 0 고정(A<B<C 조건)
    // B<C가 되야하므로 시작01 1 이후 10 1이 있어야함(그사이는 00 0)
    //  
    // K자리수중 1개를 골라서 01 1,그 뒤로 매 비트당 01 1, 10 1, 11 0, 00 0 4종류 가능
    // 이진수로 k자리>> 숫자 2^k-1
    // 4자리인경우 
    // (0)(1)?? => 4*4=16개 || (0)0(1)? 4개 || (0)0(1)? 4개 || (0)00(1) 2*2=4개 
    // (1)(0)?? => 4*4=16개 || (1)1(0)? 4개 || (1)0(0)? 4개 || (1)ab(0) 2*2=4개 => 28개
    // (1)(1)?? => 4*4=16개 || (1)1(1)? 4개 || (1)0(1)? 4개 || (1)ab(1) 2*2=4개 
    // (0)(1)? =>4개 || (0)0(1) 1개 || (0)0(1) 1개
    // (1)(0)? =>4개 || (1)0(0) 1개 || (1)1(0) 1개 => 6개
    // (1)(1)? =>4개 || (1)0(1) 1개 || (1)1(1) 1개
    // 01 1개
    // 10 1개 ==> 총 35개
    // 11 1개
    // \Sigma_{i=0}^{i<=k-2} (4^(k-2-0))*(2^(0))+(4^(k-2-1))*(2^(1))+(4^(k-2-2))*(2^(2))
    // \Sigma_{i=0}^{i<=k-2} (2^(2k-4-i))
    // == 2^(2k-4)*2*(1-(1/2)^(k-2+1))
    // ll total=0;
    // for(int i=2; i<=K; ++i){
    //     ll tmp=rec(2,i-2+1)%divid;
    //     total=(total%divid+(rec(2,2*i-4+1))%divid-rec(2,i-2)%divid)%divid;
    //     // total=(total%divid+((rec(2,2*i-4)%divid)*2*((tmp-1)%divid)*(rec(tmp,divid-2)%divid))%divid)%divid;
    // }
    // 수식정리하면 2/3*(4^(k-1)-1)*(2^(k-1)-1)이므로 
    ll tmp1=(2*((rec(4,K-1)%divid-1)%divid))%divid;
    ll tmp2=((rec(3,divid-2)%divid))%divid;
    ll tmp3=(rec(2,K-1)%divid-1)%divid;
    ll tmp4=(tmp1*tmp2)%divid;
    ll total=(tmp4-tmp3+divid)%divid;
    // cout<<tmp1<<'\n';
    // cout<<tmp2<<'\n';
    // cout<<tmp3<<'\n';
    // cout<<tmp4<<'\n';
    cout<<total<<'\n';
    // ll R=K/2;
    // ll tmp=1, und=1;
    // for(ll i=2; i<=K; ++i){
    //     tmp=((tmp%divid)*i)%divid;
    //     if(i==R || i==K-R){
    //         und=((und%divid)*tmp)%divid;
    //         if(R==K-R) und=((und%divid)*tmp)%divid;
    //     }
    // }
    // ll sol=((tmp%divid)*(rec(und,divid-2)%divid))%divid;
    // cout<<sol<<'\n';
}