#include<iostream>
#include<vector>
using namespace std;
int dir[3]={1,0,-1};
int main(){ //17484
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    vector<vector<int>> arr(N,vector<int>(M));
    vector<vector<vector<int>>> dp(N,vector<vector<int>>(M,vector<int>(3,601)));
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cin>>arr[i][j];
        }
    }
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            for(int k=0; k<3; ++k){
                int y=j+dir[k];

                if(i==0) dp[i][j][k]=arr[i][j];
                else if(y<0 || y>=M) continue;
                else{
                    for(int l=0; l<3; ++l){
                        if(k==l) continue;
                        dp[i][j][k]=min(dp[i][j][k],dp[i-1][y][l]);
                    }
                    dp[i][j][k]+=arr[i][j];
                }
            }
        }
    }
    int sol=601;
    for(int j=0; j<M; ++j){
        for(int k=0; k<3; ++k){
            sol=min(sol,dp[N-1][j][k]);
        }
    }
    // for(int i=0; i<N; ++i){
    //     for(int j=0; j<M; ++j){
    //         for(int k=0; k<3; ++k){
    //             cout<<dp[i][j][k]<<' ';
    //         }cout<<"  ";
    //     }cout<<'\n';
    // }
    cout<<sol<<'\n';
}