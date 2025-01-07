#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int dirx[4]={-1,0,0,1};
int diry[4]={0,-1,1,0};
// bool checksort(pair<int,int> pa1, pair<int,int> pa2){
//     if(pa1.first < pa2.first || pa1.first > pa2.second) return pa1.first < pa2.first;
//     else return pa1.second < pa2.second;
// }
int main(){//16236
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int arr[N][N];
    // , dist[N][N];
    queue<pair<int,int>> qu;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin>>arr[i][j];
            // dist[i][j]=-1;
            if(arr[i][j]==9){
                qu.push({i,j});
                arr[i][j]=0;
                // dist[i][j]=0;
            }
        }
    }
    int time=0, rank=2, levelcnt=0;
    while(true){
        int dist[N][N];
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                dist[i][j]=-1;
            }
        }
        dist[qu.front().first][qu.front().second]=0;
        int mindist=2147483647;
        vector<pair<int,int>> cand;

        
        while(!qu.empty()){
            int x=qu.front().first;
            int y=qu.front().second;
            qu.pop();
            for(int i=0; i<4; ++i){
                int nx=x+dirx[i];
                int ny=y+diry[i];
                if(nx<0 || nx>=N) continue;
                if(ny<0 || ny>=N) continue;
                if(dist[nx][ny]>=0) continue;
                if(arr[nx][ny] > rank) continue;

                dist[nx][ny]=dist[x][y]+1;
                // cout<<nx<<' '<<ny<<' '<<dist[nx][ny]<<'\n';
            
                if(arr[nx][ny]!=0 && arr[nx][ny] < rank){
                    if(dist[nx][ny]<mindist){
                        mindist=dist[nx][ny];
                        cand.clear();
                        cand.push_back({nx,ny});
                    }
                    else if(dist[nx][ny]==mindist){
                        cand.push_back({nx,ny});
                    }
                }
                qu.push({nx,ny});
            }
        }
        if(cand.empty()) break;
        sort(cand.begin(), cand.end());
        int tmpx=cand[0].first;
        int tmpy=cand[0].second;
        time+=dist[tmpx][tmpy];
        arr[tmpx][tmpy]=0;
        qu.push({tmpx,tmpy});

        ++levelcnt;
        if(levelcnt==rank){
            ++rank;
            levelcnt=0;
        }
    }
    cout<<time<<'\n';
}