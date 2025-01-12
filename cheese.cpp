#include<iostream>
#include<queue>
using namespace std;
int dirx[4]={1,-1,0,0};
int diry[4]={0,0,1,-1};
int main(){//2638
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    int arr[N][M];
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cin>>arr[i][j];
        }
    }
    int time=0;
    queue<pair<int,int>> qu;

    while(true){
        ++time;
        // for(int i=0; i<N; ++i){
        //     for(int j=0; j<M; ++j){
        //         if(arr[i][j]==-1) arr[i][j]=0;
        //     }
        // }
        qu.push({0,0});
        arr[0][0]=-1;
        while(!qu.empty()){
            int x=qu.front().first;
            int y=qu.front().second;
            qu.pop();
            for(int i=0; i<4; ++i){
                int nx=x+dirx[i];
                int ny=y+diry[i];
                if(nx<0 || nx>=N) continue;
                if(ny<0 || ny>=M) continue;
                if(arr[nx][ny]==-1) continue;
                if(arr[nx][ny]>2) continue;

                if(arr[nx][ny]>0) ++arr[nx][ny];

                else if(arr[nx][ny]==0){
                    qu.push({nx,ny});
                    arr[nx][ny]=-1;
                }
            }
        }

        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                if(arr[i][j]>2 || arr[i][j]==-1) arr[i][j]=0;
                if(arr[i][j]==2) arr[i][j]=1;
            }
        }//초기화

        bool triger=false;
        for(int i=1; i<N-1; ++i){
            for(int j=1; j<M-1; ++j){
                if(arr[i][j]>0){
                    triger=true;
                    break;
                }
            }
            if(triger) break;
        }
        if(!triger) break;

    }
    cout<<time<<'\n';
}