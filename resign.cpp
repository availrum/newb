#include<iostream>
using namespace std;
int main(){//14501
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,t;
    cin>>N;
    int task[N+1]={0,};
    int price[N+1]={0,};
    for(int i=0; i<N; ++i){
        cin>>task[i]>>price[i];
    }
    int dp[N+1]={0,};
    for(int i=N-1; i>=0; --i){
        for(int j=i+(task[i]); j<=N; ++j){
            dp[i]=max(dp[j]+price[i], dp[i]);
        }
    }
    int sol=0;
    for(int i=0; i<N; ++i){
        // cout<<dp[i]<<' ';
        sol=max(sol,dp[i]);
    }
    // cout<<'\n';
    cout<<sol<<'\n';
}