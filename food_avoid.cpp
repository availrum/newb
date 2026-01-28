#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int dirx[4]={0,1,0,-1};
int diry[4]={1,0,-1,0};
int main(){ //1743
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M,K;
    cin>>N>>M>>K;
    vector<vector<bool>> minimap(N,vector<bool>(M,false));
    for(int i=0; i<K; ++i){
        int x,y;
        cin>>x>>y;
        minimap[x-1][y-1]=true;
    }
    vector<vector<bool>> visited(N,vector<bool>(M,false));
    int max_cnt=0;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            if(!minimap[i][j] || visited[i][j]) continue;
            queue<pair<int,int>> qu;
            qu.push({i,j});
            visited[i][j]=true;
            int cnt=1;
            while(!qu.empty()){
                int x=qu.front().first;
                int y=qu.front().second;
                qu.pop();
                for(int k=0; k<4; ++k){
                    int nx=x+dirx[k];
                    int ny=y+diry[k];
                    if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
                    if(!minimap[nx][ny] || visited[nx][ny]) continue;
                    qu.push({nx,ny});
                    visited[nx][ny]=true;
                    ++cnt;
                }
            }
            max_cnt=max(max_cnt,cnt);
        }
    }
    cout<<max_cnt<<'\n';
}