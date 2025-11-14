#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int dirx[4]={1,-1,0,0};
int diry[4]={0,0,1,-1};
int main(){ //4485
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    int tcase=1;
    while(cin>>N){
        if(N==0) break;
        vector<vector<int>> cave(N,vector<int>(N)), cost(N,vector<int>(N,2147483647));
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                cin>>cave[i][j];
                cost[i][j]=2147483647;
            }
        }
        queue<pair<int,int>> qu;
        qu.push({0,0});
        cost[0][0]=cave[0][0];
        while(!qu.empty()){
            int x=qu.front().first;
            int y=qu.front().second;
            qu.pop();
            for(int i=0; i<4; ++i){
                int nx=x+dirx[i];
                int ny=y+diry[i];
                if(nx<0 || nx>=N) continue;
                if(ny<0 || ny>=N) continue;
                if(cost[nx][ny]>cost[x][y]+cave[nx][ny]){
                    cost[nx][ny]=cost[x][y]+cave[nx][ny];
                    qu.push({nx,ny});
                }
            }
        }
        cout<<"Problem "<<tcase<<": "<<cost[N-1][N-1]<<'\n';
        ++tcase;
    }
    
}