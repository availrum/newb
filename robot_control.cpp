#include<iostream>
#include<vector>
using namespace std;
const int con=-100000000;
int main(){ //2169
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    vector<vector<int>> arr(N,vector<int>(M));
    vector<vector<vector<int>>> dp(N,vector<vector<int>>(M,vector<int>(3,con)));
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cin>>arr[i][j];
        }
    }
    for(int i=0; i<N; ++i){
        if(i==0){
            dp[i][0][0]=arr[i][0];

            for(int j=1; j<M; ++j){
                dp[i][j][0]=dp[i][j-1][0]+arr[i][j];
            }
        }
        else{
            for(int j=0; j<M; ++j){
                int tmp=con;
                for(int k=0; k<3; ++k) tmp=max(tmp,dp[i-1][j][k]); 
                dp[i][j][1]=tmp+arr[i][j];
            }
            dp[i][0][0]=dp[i][0][1];
            dp[i][M-1][2]=dp[i][M-1][1];
            for(int j=1; j<M; ++j){
                dp[i][j][0]=max(dp[i][j-1][1],dp[i][j-1][0])+arr[i][j];
            }
            for(int j=M-2; j>=0; --j){
                dp[i][j][2]=max(dp[i][j+1][1],dp[i][j+1][2])+arr[i][j];
            }
        }
    }
    int sol=con;
    for(int k=0; k<3; ++k){
        sol=max(sol,dp[N-1][M-1][k]);
    }
    cout<<sol<<'\n';
}