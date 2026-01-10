#include<iostream>
#define ll long long int
using namespace std;
int main(){ //2004
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    ll cnt2=0, cnt5=0;
    ll multi=max(n-m,m)+1;
    ll divid=min(n-m,m);
    ll idx5=5, idx2=2;
    if(n>=multi){
        while(n>=idx5){
            if(multi>=idx5){
                if(multi%idx5!=0){
                    ll tmp=1+multi/idx5;
                    if(tmp*idx5<=n) cnt5+=1+(n-tmp*idx5)/idx5;
                }
                else{
                    ll tmp=multi/idx5;
                    cnt5+=1+(n-tmp*idx5)/idx5;
                }
            }
            else cnt5+=1+(n-idx5)/idx5;
            idx5*=5;
        }
        while(n>=idx2){
            if(multi>=idx2){
                if(multi%idx2!=0){
                    ll tmp=1+multi/idx2;
                    if(tmp*idx2<=n) cnt2+=1+(n-tmp*idx2)/idx2;
                }
                else{
                    ll tmp=multi/idx2;
                    cnt2+=1+(n-tmp*idx2)/idx2;
                }
            }
            else cnt2+=1+(n-idx2)/idx2;
                // cout<<idx2<<' '<<cnt2<<" check"<<'\n';
            idx2*=2;
        }
        // cout<<cnt2<<' '<<cnt5<<'\n';
        idx5=5, idx2=2;
        while(divid>=idx5){
            cnt5-=divid/idx5;

            idx5*=5;
        }
        while(divid>=idx2){
            cnt2-=divid/idx2;

            idx2*=2;
        }
    }
    // 10C_5의 경우 10!/(5!*5!)
    // 6 8 10으로 2의개수 4개, 10으로 5의개수 1개
    // cout<<multi<<' '<<divid<<'\n';
    // cout<<cnt2<<' '<<cnt5<<'\n';
    cout<<min(cnt2,cnt5)<<'\n';
    // 0의 개수는 min(2의개수,5의개수)의 개수와 같다
    // nCm = n!/(m! * (n-m)!)
    // 100C15 >> (85*...*100) / (2*...*15)
    // 90=(15)*(6), 98=(14)*(7), 91/(13)=7, 96=(12)*(8), 88=(11)*(4)*(2)
    // 100/(10)=100, 99=(9)*11, 95=(5)*19, 93=(3)*31, ... (n-m)!은 다 나눠짐
}