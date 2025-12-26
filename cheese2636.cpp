#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int dirx[4]={0,1,0,-1};
int diry[4]={1,0,-1,0};
int main(){ //2636
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    int pan[N][M];
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cin>>pan[i][j];
        }
    }
    int num_of_cheese=1, cur_time=0, last_cheese=0;
    while(num_of_cheese){
    // cout<<'\n';
        vector<vector<bool>> onair(N,vector<bool>(M,false));
        num_of_cheese=0;
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                if(pan[i][j]==0) continue;
                ++num_of_cheese;
            }
        }
        if(!num_of_cheese) break;
        last_cheese=num_of_cheese;
        queue<pair<int,int>> qu;
        qu.push({0,0});
        onair[0][0]=true;
        while(!qu.empty()){
            int x=qu.front().first;
            int y=qu.front().second;
            qu.pop();
            for(int i=0; i<4; ++i){
                int nx=x+dirx[i];
                int ny=y+diry[i];
                if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
                else if(onair[nx][ny]) continue;
                onair[nx][ny]=true;
                if(!pan[nx][ny]) qu.push({nx,ny});
            }
        }
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                if(onair[i][j]) pan[i][j]=0;
            }
        }
        ++cur_time;
        // for(int i=0; i<N; ++i){
        //     for(int j=0; j<M; ++j){
        //         cout<<pan[i][j]<<' ';
        //     }cout<<'\n';
        // }
    }
    cout<<cur_time<<'\n';
    cout<<last_cheese<<'\n';
}