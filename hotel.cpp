#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){ //1106
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int C,N,t;
    cin>>C>>N;
    vector<pair<int,int>> arr(N);
    int max_num_people=2001;
    vector<int> dp(max_num_people+1,2000000000);
    dp[0]=0;
    for(int i=0; i<N; ++i){
        int cost;
        int get;
        cin>>cost>>get;
        arr[i]={cost,get};
        //arr[i];
        for(int j=1; get*j<=max_num_people; ++j){
            dp[get*j]=min(dp[get*j], cost*j);
        }
    }
    int mincost=2147483647;
    for(int i=0; i<=max_num_people; ++i){
        for(int j=0; j<N; ++j){
            int cost=arr[j].first;
            int get=arr[j].second;
            for(int k=0; i+get*k<=max_num_people; ++k){
                dp[i+get*k]=min(dp[i+get*k],dp[i]+dp[get]*k);
            }
        }
        if(i>=C) mincost=min(mincost,dp[i]);
    }
    // for(int i=1; i<=max_num_people; ++i){
    //     cout<<dp[i]<<' ';
    // }cout<<'\n';
    cout<<mincost<<'\n';
}