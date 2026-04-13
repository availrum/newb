#include<iostream>
#include<vector>
using namespace std;
int main(){ //13398
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,t;
    cin>>N;
    vector<vector<int>> dp(N,vector<int>(2,-1001));
    for(int i=0; i<N; ++i){
        cin>>t;
        if(i==0){
            dp[i][0]=t;
        }
        else{
            dp[i][0]=max(t,dp[i-1][0]+t);
            dp[i][1]=max(dp[i-1][0],dp[i-1][1]+t);
        }
    }
    int sol=-100000001;
    for(int i=0; i<N; ++i){
        for(int j=0; j<2; ++j){
            // cout<<dp[i][j]<<' ';
            sol=max(sol,dp[i][j]);
        }
        // cout<<'\n';
    }
    cout<<sol<<'\n';
}