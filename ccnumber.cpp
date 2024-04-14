#include<iostream>
#include<queue>
#include<vector>
using namespace std;
bool visited[1001];
vector<int> graph[1001];

int main(){//11724
    int N,M,tmps,tmpe,cnt=0,vod=0;
    cin>>N>>M;
    queue<int> qu;
    for(int i=0; i<M; i++){
        cin>>tmps>>tmpe;
        graph[tmps-1].push_back(tmpe-1);
        graph[tmpe-1].push_back(tmps-1);
    }
    for(int j=0; j<N; j++){
        if(visited[j]) continue;
        if(!graph[j].size()){
            vod++;
            continue;
        }
        visited[j]=true;
        qu.push(j);
        while(!qu.empty()){
            int x=qu.front();
            qu.pop();
            for(int i=0; i<graph[x].size(); i++){
                if(visited[graph[x][i]]==true) continue;
                visited[graph[x][i]]=true;
                qu.push(graph[x][i]);
            }
            if(qu.empty()) cnt++;
        }
    }
    // for(int i=0; i<N; i++){
    //     for(int j=0; j<graph[i].size(); j++){
    //         cout<<graph[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    cout<<cnt+vod<<'\n';
}