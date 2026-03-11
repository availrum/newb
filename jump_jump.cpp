#include<iostream>
#include<vector>
using namespace std;
int main(){ //11060
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int maze[N],dp[N+1]={0,};
    for(int i=0; i<N; ++i){
        cin>>maze[i];
    }
    for(int i=0; i<N; ++i){
        if(maze[i]==0) continue;
        for(int j=1; j<=maze[i]; ++j){
            if(i+j>=N) break;
            if(i!=0 && dp[i]==0) break;
            if(dp[i+j]==0 || dp[i+j]>dp[i]+1) dp[i+j]=dp[i]+1;
        }
    }
    // for(int i=0; i<N; ++i){
    //     cout<<dp[i]<<' ';
    // }cout<<'\n';
    if(dp[N-1]>0 || N==1) cout<<dp[N-1]<<'\n';
    else cout<<"-1\n";
} 