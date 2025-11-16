#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;
int dirx[4]={0,1,0,-1};
int diry[4]={1,0,-1,0};
int main(){ //1926
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    int paper[n][m];
    bool visited[n][m];
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin>>paper[i][j];
            visited[i][j]=false;
        }
    }
    queue<pair<int,int>> qu;
    int idx=1, sol=0;
    unordered_map<int,int> cnt;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(visited[i][j]) continue;
            if(paper[i][j]==0) continue;
            qu.push({i,j});
            visited[i][j]=true;
            ++cnt[idx];
            while(!qu.empty()){
                int x=qu.front().first;
                int y=qu.front().second;
                qu.pop();
                for(int k=0; k<4; ++k){
                    int nx=x+dirx[k];
                    int ny=y+diry[k];
                    if(nx<0 || nx>=n) continue;
                    if(ny<0 || ny>=m) continue;
                    if(visited[nx][ny]) continue;
                    if(paper[x][y]!=paper[nx][ny]) continue;
                    visited[nx][ny]=true;
                    ++cnt[idx];
                    qu.push({nx,ny});
                }
            }
            sol=max(sol,cnt[idx]);
            ++idx;
        }
    }
    cout<<idx-1<<'\n';
    cout<<sol<<'\n';
}