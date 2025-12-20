#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int dirx[4]={0,1,0,-1};
int diry[4]={1,0,-1,0};
int main(){ //1261
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>M>>N;
    int maze[N][M];
    pair<bool,int> visited[N][M];
    for(int i=0; i<N; ++i){
        string st;
        cin>>st;
        for(int j=0; j<st.length(); ++j){
            maze[i][j]=st[j]-'0';
            visited[i][j]={false,0};
        }
    }
    queue<pair<int,int>> qu;
    qu.push({0,0});
    visited[0][0].first=true;
    while(!qu.empty()){
        int x=qu.front().first;
        int y=qu.front().second;
        int wall_cnt=visited[x][y].second;
        qu.pop();
        for(int i=0; i<4; ++i){
            int nx=x+dirx[i];
            int ny=y+diry[i];
            if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
            int need_break=wall_cnt;
            if(maze[nx][ny]==1) ++need_break;
            if(visited[nx][ny].first && visited[nx][ny].second<=need_break) continue;
            visited[nx][ny]={true,need_break};
            qu.push({nx,ny});
        }
    }
    cout<<visited[N-1][M-1].second<<'\n';
}