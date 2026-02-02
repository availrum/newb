#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){ //5567
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> relation(n+1);
    for(int i=0; i<m; ++i){
        int a,b;
        cin>>a>>b;
        relation[a].push_back(b);
        relation[b].push_back(a);
    }
    queue<pair<int,int>> qu;
    vector<int> visited(n+1,0);
    qu.push({1,0});
    visited[1]=1;
    while(!qu.empty()){
        int x=qu.front().first;
        int dist=qu.front().second;
        qu.pop();
        for(int i=0; i<relation[x].size(); ++i){
            if(dist>=2) continue;
            else if(!visited[relation[x][i]] || visited[relation[x][i]]>dist+1){
                visited[relation[x][i]]=dist+1;
                qu.push({relation[x][i],dist+1});
            }
        }
    }
    int cnt=0;
    for(int i=2; i<=n; ++i) if(visited[i]) ++cnt;
    cout<<cnt<<'\n';
}