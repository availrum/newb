#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int dirx[4]={1,-1,0,0};
int diry[4]={0,0,1,-1};
int main(){//4963
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int M,N,K;
    cin>>M>>N>>K;
    int graph[N][M];
    bool visited[N][M];
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            graph[i][j]=1;
            visited[i][j]=false;
        }
    }
    for(int i=0; i<K; ++i){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        for(int j=x1; j<x2; ++j){
            for(int k=y1; k<y2; ++k){
                graph[j][k]=0;
            }
        }
    }
    queue<pair<int,int>> qu;
    vector<int> sol;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            if(!graph[i][j] || visited[i][j]) continue;
            int cnt=1;
            qu.push({i,j});
            visited[i][j]=true;
            while(!qu.empty()){
                int x= qu.front().first;
                int y=qu.front().second;
                qu.pop();
                for(int k=0; k<4; ++k){
                    int nx=x+dirx[k];
                    int ny=y+diry[k];
                    if(!graph[nx][ny] || visited[nx][ny]) continue;
                    if(nx>=N || nx<0) continue;
                    if(ny>=M || ny<0) continue;
                    qu.push({nx,ny});
                    visited[nx][ny]=true;
                    ++cnt;
                }
            }
            sol.push_back(cnt);
        }
    }
    sort(sol.begin(), sol.end());
    cout<<sol.size()<<'\n';
    for(int i=0; i<sol.size(); ++i){
        cout<<sol[i];
        if(i!=sol.size()-1) cout<<' ';
        else cout<<'\n';
    }
    
}