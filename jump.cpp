#include<iostream>
using namespace std;
#define ll long long int
int dirx[2]={0,1};
int diry[2]={1,0};
int main(){ //1890
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,t;
    cin>>N;
    ll board[N][N], dp[N][N];
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin>>board[i][j];
            dp[i][j]=0;
        }
    }
    dp[0][0]=1;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            if(board[i][j]==0) continue;
            for(int k=0; k<2; ++k){
                int x=i+board[i][j]*dirx[k];
                int y=j+board[i][j]*diry[k];
                if(x>=N || y>=N) continue;
                dp[x][y]+=dp[i][j];
            }
        }
    }
    // cout<<'\n';
    // for(int i=0; i<N; ++i){
    //     for(int j=0; j<N; ++j){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    cout<<dp[N-1][N-1]<<'\n';
}