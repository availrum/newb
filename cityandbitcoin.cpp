#include<iostream>
#include<queue>
using namespace std;
int dirx[2]={1,0};
int diry[2]={0,1};
int main(){//13237
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    int arr[M][N];
    int visited[M][N];
    for(int i=0; i<M; ++i){
        for(int j=0; j<N; ++j){
            cin>>arr[i][j];
            visited[i][j]=false;
        }
    }
    queue<pair<int,int>> qu;
    qu.push({0,0});
    visited[0][0]=true;
    while(!qu.empty()){
        int x= qu.front().first;
        int y= qu.front().second;
        qu.pop();
        for(int i=0; i<2; ++i){
            int nx=x+dirx[i];
            int ny=y+diry[i];
            if(nx>=M || nx<0) continue;
            if(ny>=N || ny<0) continue;
            if(visited[nx][ny] || !arr[nx][ny]) continue;
            qu.push({nx,ny});
            visited[nx][ny]=visited[x][y]+1;
        }
    }
    if(visited[M-1][N-1]) cout<<"Yes"<<'\n';
    // cout<<visited[M-1][N-1]<<'\n';
    //  
    else cout<<"No"<<'\n';
}