#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int dirx[4]={0,1,0,-1};
int diry[4]={1,0,-1,0};
int main(){ //2146
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,t;
    cin>>N;
    vector<vector<int>> world(N,vector<int>(N,0));
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin>>world[i][j];
        }
    }
    int min_cost=10001, idx=2;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            if(world[i][j]==0) continue;
            else if(world[i][j]>1) continue;
            queue<pair<int,int>> qu;
            qu.push({i,j});
            world[i][j]=idx;
            while(!qu.empty()){
                int x=qu.front().first;
                int y=qu.front().second;
                qu.pop();
                for(int k=0; k<4; ++k){
                    int nx=x+dirx[k];
                    int ny=y+diry[k];
                    if(nx<0 || nx>=N || ny<0 || ny>=N) continue;
                    else if(world[nx][ny]==0) continue;
                    else if(world[nx][ny]==idx) continue;
                    qu.push({nx,ny});
                    world[nx][ny]=idx;
                }
            }
            ++idx;
        }
    }
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            if(world[i][j]==0) continue;
            queue<pair<int,int>> qu;
            vector<vector<int>> visited(N,vector<int>(N,-1));
            qu.push({i,j});
            visited[i][j]=0;
            while(!qu.empty()){
                int x=qu.front().first;
                int y=qu.front().second;
                qu.pop();
                for(int k=0; k<4; ++k){
                    int nx=x+dirx[k];
                    int ny=y+diry[k];
                    if(nx<0 || nx>=N || ny<0 || ny>=N) continue;
                    else if(world[nx][ny]==world[i][j]) continue;
                    else if(world[nx][ny]>1){
                        if(world[x][y]==1) continue;
                        if(visited[nx][ny]==-1 || visited[nx][ny]>visited[x][y]){
                            visited[nx][ny]=visited[x][y];
                            min_cost=min(min_cost,visited[nx][ny]);
                        }
                    }
                    else if(world[nx][ny]==0 && (visited[nx][ny]==-1 || visited[nx][ny]>visited[x][y]+1)){
                        visited[nx][ny]=visited[x][y]+1;
                        qu.push({nx,ny});
                    }
                }
            }
        }
    }
    cout<<min_cost<<'\n';
}