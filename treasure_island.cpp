#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int dirx[4]={0,1,0,-1};
int diry[4]={1,0,-1,0};
int main(){ //2589
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    vector<vector<int>> tmap(N, vector<int>(M,0));
    for(int i=0; i<N; ++i){
        string st;
        cin>>st;
        for(int j=0; j<st.length(); ++j){
            if(st[j]=='L') tmap[i][j]=1;
        }
    }
    int max_dist=0;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            if(!tmap[i][j]) continue;
            vector<vector<pair<bool,int>>> dist(N, vector<pair<bool,int>>(M,{false,0}));
            queue<pair<int,int>> qu;
            qu.push({i,j});
            dist[i][j].first=true;
            while(!qu.empty()){
                int x=qu.front().first;
                int y=qu.front().second;
                qu.pop();
                for(int k=0; k<4; ++k){
                    int nx=x+dirx[k];
                    int ny=y+diry[k];
                    if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
                    else if(!tmap[nx][ny]) continue;
                    else if(dist[nx][ny].first) continue;
                    qu.push({nx,ny});
                    dist[nx][ny].first=true;
                    dist[nx][ny].second=dist[x][y].second+1;
                    max_dist=max(max_dist,dist[nx][ny].second);
                }
            }
        }
    }
    cout<<max_dist<<'\n';
}