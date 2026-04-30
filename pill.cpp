#include<iostream>
#include<vector>
#define ll long long int
using namespace std;
int main(){ //4811
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // W개수와 H개수가 같아야함(도중에 H개수가 더많아지면 안됨)
    // 2면 
    // WWHH or WHHH
    // 3이면
    // WWWHHH or WWHHWH or WWHWHH or WHWHWH
    ll N;
    while(cin>>N){
        if(N==0) break;
        vector<vector<vector<ll>>> dp(2*N+1,vector<vector<ll>>(N+1,vector<ll>(N+1,0)));
        // dp[0][N-1][1]=1; // 0일차의 결론
        dp[0][N][0]=1;

        for(int i=1; i<=2*N; ++i){
            for(int j=0; j<=N; ++j){
                for(int k=0; k<=N; ++k){
                    if(dp[i-1][j][k]){
                        if(j>0) dp[i][j-1][k+1]+=dp[i-1][j][k];
                        if(k>0) dp[i][j][k-1]+=dp[i-1][j][k];
                    }
                }
            }
        }
        cout<<dp[2*N][0][0]<<'\n';
    }
}