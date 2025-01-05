#include<iostream>
#include<queue>
using namespace std;
int N,M, maxcnt;
int arr[8][8];
int dirx[4]={1,-1,0,0};
int diry[4]={0,0,1,-1};
void btr(int num){
    if(num==3){
        int arrcpy[N][M];
        queue<pair<int,int>> qu;
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                arrcpy[i][j]=arr[i][j];
                if(arr[i][j]==2) qu.push({i,j});
            }
        }
        while(!qu.empty()){
            int x=qu.front().first;
            int y=qu.front().second;
            qu.pop();
            for(int i=0; i<4; ++i){
                int nx=x+dirx[i];
                int ny=y+diry[i];
                if(nx<0 || nx>=N) continue;
                else if(ny<0 || ny>=M) continue;
                else if(arrcpy[nx][ny]==1 || arrcpy[nx][ny]==2) continue;
                qu.push({nx,ny});
                arrcpy[nx][ny]=2;
            }
        }
        int cnt=0;
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                if(arrcpy[i][j]==0) ++cnt;
            }
        }
        maxcnt=max(cnt,maxcnt);
        return;
    }
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            if(arr[i][j]==0){
                arr[i][j]=1;
                btr(num+1);
                arr[i][j]=0;
            }
        }
    }
}
int main(){//14502
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cin>>arr[i][j];
        }
    }
    btr(0);
    cout<<maxcnt<<'\n';
}