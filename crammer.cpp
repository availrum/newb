#include<iostream>
#include<vector>
using namespace std;
int main(){ //14728
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,T;
    cin>>N>>T;
    vector<vector<int>> dp(N,vector<int>(T+1,0));
    for(int i=0; i<N; ++i){
        int K,S;
        cin>>K>>S;
        if(i==0){
            for(int j=K; j<=T; ++j) dp[i][j]=S;
            continue;
        }
        for(int j=1; j<=T; ++j){
            if(j-K>=0) dp[i][j]=max(dp[i-1][j],max(dp[i][j-1],dp[i-1][j-K]+S));
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    // for(int i=0; i<N; ++i){
    //     for(int j=0; j<=T; ++j){
    //         cout<<dp[i][j]<<' ';
    //     }cout<<'\n';
    // }
    cout<<dp[N-1][T]<<'\n';
}