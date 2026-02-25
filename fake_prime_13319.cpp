#include<iostream>
#define ll long long int
using namespace std;
int main(){ //13319
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //카마이클수
    ll N=84;
    // cin>>N;
    ll cnt=0,total_cnt=0;
    while(total_cnt<3){
        ++N;
        ll num1=6*N+1;
        for(ll i=2; i*i<=num1; ++i){
            if(num1%i==0){
                ++cnt;
            }
        }
        if(!cnt) ++total_cnt;
        cnt=0;
        ll num2=12*N+1, num3=18*N+1;
        for(ll i=2; i*i<=num2; ++i){
            if(num2%i==0){
                ++cnt;
            }
        }
        if(!cnt) ++total_cnt;
        cnt=0;
        for(ll i=2; i*i<=num3; ++i){
            if(num3%i==0){
                ++cnt;
            }
        }
        if(!cnt) ++total_cnt;
        cnt=0;
        if(total_cnt>=3){
            cout<<num1<<'\n';
            cout<<num1*num2*num3<<'\n';
            break;
        }
        total_cnt=0;
    }
    cout<<"1299963601 601\n";
}