#include<iostream>
#include<queue>
using namespace std;
int dirx[4]={0,1,0,-1};
int diry[4]={1,0,-1,0};
struct pos{
    int x;
    int y;
    int dir;
};
int main(){ //32964
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,t;
    cin>>N;
    bool check[2][N];
    char puzzle[2][N];
    for(int i=0; i<2; ++i){
        for(int j=0; j<N; ++j){
            cin>>puzzle[i][j];
            check[i][j]=false;
        }
    }
    queue<pos> qu;
    qu.push({0,0,0});
    while(!qu.empty()){
        int x=qu.front().x;
        int y=qu.front().y;
        int dir=qu.front().dir;
        qu.pop();
        // cout<<x<<' '<<y<<' '<<dir<<'\n';
        if(puzzle[x][y]=='L'){
            for(int i=-1; i<=1; i+=2){
                int ndir=dir+i;
                if(ndir>3) ndir%=4;
                else if(ndir<0) ndir+=4;
                int nx=x+dirx[ndir];
                int ny=y+diry[ndir];
                if(nx>1 || nx<0 || ny>=N || ny<0) continue;
                else if(ndir==2) continue;
                qu.push({nx,ny,ndir});
            }
        }
        else if(puzzle[x][y]=='I'){
            if(dir==0 && y+1<N){
                qu.push({x,y+1,dir});
            }
        }
        else if(x==0 && y==0){
            qu.push({1,0,1});
            qu.push({0,1,0});
        }
        check[x][y]=true;
    }
    if(check[1][N-1]) cout<<"YES\n";
    else cout<<"NO\n";
}