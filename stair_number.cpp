#include<iostream>
#include<vector>
using namespace std;
const int con=1000000000;
int dp[101][10][1<<10];
int main(){ //1562
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,cnt=0;
    cin>>N;
    for(int i=1; i<=N; ++i){
        if(i==1){
            for(int j=1; j<10; ++j){
                dp[i][j][(1<<j)]=1;
            }
            continue;
        }
        for(int j=0; j<10; ++j){
            if(j-1>=0){
                for(int k=0; k<(1<<10); ++k){
                    dp[i][j][(k | (1<<j))]=((dp[i][j][(k | (1<<j))])%con+(dp[i-1][j-1][k])%con)%con;
                }
            }
            if(j+1<10){
                for(int k=0; k<(1<<10); ++k){
                    dp[i][j][(k | (1<<j))]=((dp[i][j][(k | (1<<j))])%con+(dp[i-1][j+1][k])%con)%con;
                }
            }
        }
    }
    for(int j=0; j<10; ++j){
        cnt=(cnt+dp[N][j][(1<<10)-1])%con;
    }
    cout<<cnt<<'\n';
    // for(int i=0; i<10; ++i) cout<<dp[1][i][(1<<i)];
    // cout<<'\n';
}