#include<iostream>
#include<vector>
using namespace std;
int min_cost=2147483647;
void rec(vector<vector<int>>& cost, vector<bool> visited, int start, int country, int cur){
    if(cur>min_cost) return;
    for(int i=0; i<visited.size(); ++i){
        if(visited[i]) continue;
        if(cost[country][i]==0) continue;

        cur+=cost[country][i];
        visited[i]=true;
        rec(cost,visited,start,i,cur);
        visited[i]=false;
        cur-=cost[country][i];
    }
    bool flag=true;
    for(int i=0; i<visited.size(); ++i){
        if(!visited[i]){
            flag=false;
            break;
        }
    }
    if(flag && cost[country][start]!=0){
        min_cost=min(min_cost,cur+cost[country][start]);
        // cout<<min_cost<<'\n';
    }
}
int main(){ //10971
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,t;
    cin>>N;
    vector<vector<int>> cost(N,vector<int>(N,0));
    vector<bool> visited(N,false);
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin>>cost[i][j];
        }
    }
    for(int i=0; i<N; ++i){
        visited[i]=true;
        rec(cost,visited,i,i,0);
        visited[i]=false;
    }
    cout<<min_cost<<'\n';
}