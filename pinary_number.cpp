#include<iostream>
using namespace std;
int main(){ //2193
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    long long dp[N][2];
    dp[0][0]=0;
    dp[0][1]=1;
    for(int i=1; i<N; ++i){
        dp[i][0]=dp[i-1][0]+dp[i-1][1];
        dp[i][1]=dp[i-1][0];
    }
    cout<<dp[N-1][0]+dp[N-1][1]<<'\n';
}