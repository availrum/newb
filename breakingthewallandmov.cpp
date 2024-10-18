#include<iostream>
#include<queue>
using namespace std;
int gtx[4]={1,-1,0,0};
int gty[4]={0,0,1,-1};
struct current{
    int cx;
    int cy;
    int cwall;
    int cdistance;
};
int main(){//2206
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    int arr[N][M],dist[N][M];
    bool visited[N][M];
    string st;
    for(int i=0; i<N; ++i){
        cin>>st;
        for(int j=0; j<M; ++j){
            arr[i][j]=st[j]-'0';
            dist[i][j]=2147483646;
            visited[i][j]=false;
        }
    }
    queue<current> qu;
    qu.push({0,0,0,1});
    dist[0][0]=1;
    visited[0][0]=true;
    while(!qu.empty()){
        current tmp=qu.front();
        int x=tmp.cx;
        int y=tmp.cy;
        int wall=tmp.cwall;
        int distance=tmp.cdistance;
        qu.pop();
        for(int i=0; i<4; ++i){
            int tx=x+gtx[i];
            int ty=y+gty[i];
            if(tx<0 || tx>=N) continue;
            else if(ty<0 || ty>=M) continue;
            else if(arr[tx][ty]==1){
                if(wall==0){
                    qu.push({tx,ty,wall+1,distance+1});
                    if(dist[tx][ty]>distance+1) dist[tx][ty]=distance+1;
                }
                else continue;
            }
            else if(arr[tx][ty]==0){
                if(dist[tx][ty]>distance+1){
                    qu.push({tx,ty,wall,distance+1});
                    dist[tx][ty]=distance+1;
                    if(wall==0) visited[tx][ty]=true;
                }
                else if(!visited[tx][ty] && wall==0){
                    qu.push({tx,ty,wall,distance+1});
                    visited[tx][ty]=true;
                    if(dist[tx][ty]>distance+1) dist[tx][ty]=distance+1;
                }
            }
        }
    }
    if(dist[N-1][M-1]==2147483646) cout<<"-1"<<'\n';
    else cout<<dist[N-1][M-1]<<'\n';
    // for(int i=0; i<N; ++i){
    //     for(int j=0; j<M; ++j){
    //         cout<<dist[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
}