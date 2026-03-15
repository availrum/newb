#include<iostream>
#include<vector>
using namespace std;
int main(){ //15486
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    pair<int,int> scd;
    vector<int> cost(N+1,0);
    int cur_max=0, sol=0;
    for(int i=0; i<N; ++i){
        cin>>scd.first>>scd.second;
        cur_max=max(cur_max,cost[i]);
        if(i+scd.first<=N){
            cost[i+scd.first]=max(cost[i+scd.first], cur_max+scd.second);
        }
        sol=max(sol,cost[i]);
    }
    sol=max(sol,cost[N]);
    // for(int i=0; i<=N; ++i){
    //     cout<<cost[i]<<' ';
    // }cout<<'\n';

    cout<<sol<<'\n';
}