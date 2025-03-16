#include<iostream>
using namespace std;
int dirx[4]={1,-1,0,0};
int diry[4]={0,0,1,-1};
int arr[501][501];
int possible[501][501];
int N, M;
void dfs(int x, int y){
    // cout<<x<<' '<<y<<'\n';
    int cnt=0;
    for(int i=0; i<4; ++i){
        int nx=x+dirx[i];
        int ny=y+diry[i];
        if(nx>=N || nx<0) continue;
        if(ny>=M || ny<0) continue;
        if(arr[x][y] <= arr[nx][ny]) continue;
        //더 작은 값으로만 이동하니 방문지점 되돌아가는 경우x
        if(possible[nx][ny]>0){
            possible[x][y]+=possible[nx][ny];
            ++cnt;
        }
        else if(possible[nx][ny]==-1) continue;
        else{
            dfs(nx,ny);
            if(possible[nx][ny] > 0){
                possible[x][y]+=possible[nx][ny]; 
                ++cnt;
            }
        }
    }
    if(cnt==0) possible[x][y]=-1;
}
int main(){//1520
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cin>>arr[i][j];
        }
    }
    possible[N-1][M-1]=1;
    dfs(0,0);
    if(possible[0][0]!=-1) cout<<possible[0][0]<<'\n';
    else if(N==1 && M==1) cout<<"1"<<'\n';
    else cout<<"0"<<'\n';
}