#include<iostream>
#include<queue>
using namespace std;
int dirx[4]={1,-1,0,0};
int diry[4]={0,0,1,-1};
int maxi=2147483647;
struct pos{
    int x;
    int y;
};
int main(){//4179
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int R,C;
    cin>>R>>C;
    int maze[R+1][C+1],fire[R+1][C+1],dist[R+1][C+1];
    for(int i=0; i<R; ++i){
        for(int j=0; j<C; ++j){
            fire[i][j]=maxi;
            dist[i][j]=maxi;
        }
    }
    string st;
    queue<pos> qu, quf;
    for(int i=0; i<R; ++i){
        cin>>st;
        for(int j=0; j<st.length(); ++j){
            if(st[j]=='#'){
                maze[i][j]=-1;
            }
            else if(st[j]=='J'){
                qu.push({i,j});
                maze[i][j]=1;
                dist[i][j]=0;
            }
            else if(st[j]=='F'){
                quf.push({i,j});
                maze[i][j]=-1;
                fire[i][j]=0;
            }
            else maze[i][j]=1;
        }
    }
    int sol=maxi;
    while(!quf.empty()){
        int curx=quf.front().x;
        int cury=quf.front().y;
        quf.pop();
        for(int i=0; i<4; ++i){
            int nx=curx+dirx[i];
            int ny=cury+diry[i];
            if(nx>=R || nx<0) continue;
            if(ny>=C || ny<0) continue;
            if(maze[nx][ny]==-1) continue;
            if(fire[nx][ny]>fire[curx][cury]+1){
                quf.push({nx,ny});
                fire[nx][ny]=fire[curx][cury]+1;
            }
        }
    }
    while(!qu.empty()){
        int curx=qu.front().x;
        int cury=qu.front().y;
        qu.pop();
        for(int i=0; i<4; ++i){
            int nx=curx+dirx[i];
            int ny=cury+diry[i];
            if(nx>=R || nx<0 || ny>=C || ny<0){
                sol=min(sol,dist[curx][cury]+1);
                continue;
            }
            if(maze[nx][ny]==-1) continue;
            if(fire[nx][ny]<=dist[curx][cury]+1) continue;
            if(dist[nx][ny]>dist[curx][cury]+1){
                qu.push({nx,ny});
                dist[nx][ny]=dist[curx][cury]+1;
            }
        }
    }
    // for(int i=0; i<R; ++i){
    //     for(int j=0; j<C; ++j){
    //         cout<<dist[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    if(sol!=maxi) cout<<sol<<'\n';
    else cout<<"IMPOSSIBLE"<<'\n';
}