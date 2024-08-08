#include<iostream>
#include<queue>
using namespace std;
int dirx[4]={-1,1,0,0};
int diry[4]={0,0,-1,1};
bool visitedn[101][101];
bool visitedc[101][101];
int main(){//10026
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int arr[N][N];
    for(int i=0; i<N; ++i){
        string tmp;
        cin>>tmp;
        for(int j=0; j<N; ++j){
            if(tmp[j]=='B') arr[i][j]=0;
            else if(tmp[j]=='R') arr[i][j]=1;
            else if(tmp[j]=='G') arr[i][j]=-1;
        }
    }
    int cnt=0, cnt_ncow=0,cnt_cow=0;
    queue<int> qux,quy;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            if(visitedn[i][j]) continue;
            qux.push(i);
            quy.push(j);
            ++cnt_ncow;
            // cout<<i<<' '<<j<<'\n';
            while(!qux.empty()){
                int x=qux.front();
                int y=quy.front();
                qux.pop();
                quy.pop();
                for(int k=0; k<4; ++k){
                    int tx=x+dirx[k];
                    int ty=y+diry[k];
                    if(visitedn[tx][ty]) continue;
                    if(tx<0 || tx>=N) continue;
                    if(ty<0 || ty>=N) continue;
                    if(arr[x][y]!=arr[tx][ty]) continue;
                    qux.push(tx);
                    quy.push(ty);
                    visitedn[tx][ty]=true;
                }
            }
        }
    }
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            if(visitedc[i][j]) continue;
            qux.push(i);
            quy.push(j);
            ++cnt_cow;
            // cout<<i<<' '<<j<<'\n';
            while(!qux.empty()){
                int x=qux.front();
                int y=quy.front();
                qux.pop();
                quy.pop();
                for(int k=0; k<4; ++k){
                    int tx=x+dirx[k];
                    int ty=y+diry[k];
                    if(visitedc[tx][ty]) continue;
                    if(tx<0 || tx>=N) continue;
                    if(ty<0 || ty>=N) continue;
                    if(abs(arr[x][y])!=abs(arr[tx][ty])) continue;
                    qux.push(tx);
                    quy.push(ty);
                    visitedc[tx][ty]=true;
                }
            }
        }
    }
    cout<<cnt_ncow<<' '<<cnt_cow<<'\n';
}