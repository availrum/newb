#include<iostream>
#include<vector>
#define ll long long int
using namespace std;
int main(){ //5557
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N,t;
    cin>>N;
    vector<vector<ll>> dp(N,vector<ll>(21,0));
    for(int i=0; i<N; ++i){
        cin>>t;
        if(i==0){
            dp[i][t]=1;
        }
        else if(i!=N-1){
            for(int j=0; j<=20; ++j){
                if(dp[i-1][j] && j+t<=20) dp[i][j+t]+=dp[i-1][j];
                if(dp[i-1][j] && j-t>=0) dp[i][j-t]+=dp[i-1][j];
            }
        }
    }
    cout<<dp[N-2][t]<<'\n';
}