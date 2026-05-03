#include<iostream>
#include<vector>
using namespace std;
const int con=1000000000;
int dp[16][1<<16];
int tsp(int cur, int visited, vector<vector<int>>& arr){
    int n=arr.size();
    if(visited==(1<<n)-1){
        if(arr[cur][0]!=0) return arr[cur][0];
        return con;
    }
    if(dp[cur][visited]!=-1){
        return dp[cur][visited];
    }
    bool flag=true;
    for(int next=0; next<n; ++next){
        if(!(visited & (1<<next)) && arr[cur][next]!=0){
            int tmp=tsp(next, visited | (1<<next), arr);
            if(dp[cur][visited]==-1) dp[cur][visited]=tmp+arr[cur][next];
            else dp[cur][visited]=min(dp[cur][visited],tmp+arr[cur][next]);
            flag=false;
        }
    }
    if(flag) dp[cur][visited]=con;
    return dp[cur][visited];
}
int main(){ //2098
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,t;
    cin>>N;
    for(int i=0; i<16; ++i){
        for(int j=0; j<(1<<16); ++j){
            dp[i][j]=-1;
        }
    }
    vector<vector<int>> arr(N,vector<int>(N));
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin>>t;
            arr[i][j]=t;
        }
    }
    int min_cost=con;
    min_cost=min(min_cost,tsp(0,1,arr));
    // for(int i=0; i<N; ++i){
    //     for(int j=0; j<N; ++j){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    cout<<min_cost<<'\n';
}