#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int dirx[4]={0,1,0,-1};
int diry[4]={1,0,-1,0};
int main(){ //2573
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
    int cur=1, first=0;
    bool flag=true;
    // cout<<'\n';
    while(flag){
        vector<vector<int>> melt(N,vector<int>(M,0));
        flag=false;
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                if(arr[i][j]==0) continue;
                int tmp=0;
                for(int k=0; k<4; ++k){
                    int x=i+dirx[k];
                    int y=j+diry[k];
                    if(x<0 || x>=N) continue;
                    if(y<0 || y>=M) continue;
                    if(arr[x][y]!=0) continue;
                    flag=true;
                    ++tmp;
                }
                melt[i][j]=-tmp;
            }
        }
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                arr[i][j]+=melt[i][j];
                if(arr[i][j]<0) arr[i][j]=0;
            }
        }
        int cnt=0;
        queue<pair<int,int>> qu;
        vector<vector<bool>> visited(N,vector<bool>(M,false));
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                if(visited[i][j] || arr[i][j]<=0) continue; 
                qu.push({i,j});
                while(!qu.empty()){
                    int x=qu.front().first;
                    int y=qu.front().second;
                    qu.pop();
                    for(int k=0; k<4; ++k){
                        int nx=x+dirx[k];
                        int ny=y+diry[k];
                        if(nx<0 || nx>=N) continue;
                        if(ny<0 || ny>=M) continue;
                        if(arr[nx][ny]<=0) continue;
                        if(visited[nx][ny]) continue;
                        visited[nx][ny]=true;
                        qu.push({nx,ny});
                    }
                }
                ++cnt;
            }
        }
        // for(int i=0; i<N; ++i){
        //     for(int j=0; j<M; ++j){
        //         cout<<arr[i][j];
        //         if(j!=M-1) cout<<' ';
        //         else cout<<'\n';
        //     }
        // }
        // cout<<'\n';
        if(cnt>1){
            first=cur;
            break;
        }
        ++cur;
    }
    cout<<first<<'\n';
}