#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
#define ll long long int
using namespace std;
const int divi=1000000000;
int main(){//2225
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,K;
    cin>>N>>K;
    vector<vector<int>> dp(N+1,vector<int>(K+1,0));
    for(int i=0; i<=N; ++i){
        for(int j=0; j<=K; ++j){
            if(i==0 || j==1) dp[i][j]=1;
        }
    }
    
    //{0,0,0,0}-1개 =1 
    //{1,0,0,0}-4개 =4
    //{2,0,0,0}-4개 || {1,1,0,0}-6개 =10
    //{3,0,0,0}-4개 || {2,1,0,0}-12(4C2*2C1)개 || {1,1,1,0}-4개 =20
    //{4,0,0,0}-4개 || {3,1,0,0}-12개 || {2,2,0,0}-6개 || {2,1,1,0}-12개 || {1,1,1,1}-1개 =35
    //{5,0,0,0}-4 || {4,1,0,0}-12 || {3,2,0,0}-12 || {3,1,1,0}-12 || {2,2,1,0}-12 || {2,1,1,1}-4 =56
    //{6,0,0,0}-4 || {5,1,0,0}-12 || {4,2,0,0}-12 || {4,1,1,0}-12 || {3,3,0,0}-6 || {3,2,1,0}-24 || {3,1,1,1}-4 || {2,2,2,0}-4 || {2,2,1,1}-6 =84

    for(int i=1; i<=N; ++i){
        for(int k=2; k<=K; ++k){
            for(int j=i; j>=0; --j){
                dp[i][k]=((dp[i][k])%divi+(dp[j][k-1]%divi))%divi;
            }
        }
    }


    // for(int j=0; j<=K; ++j) cout<<j<<" ";
    // cout<<'\n';
    // for(int i=0; i<=N; ++i){
    //     for(int j=0; j<=K; ++j){
    //         cout<<dp[i][j];
    //         if(j!=K) cout<<' ';
    //         else cout<<" 합계"<<i<<'\n';
    //     }
    // }
    cout<<dp[N][K]<<'\n';
}