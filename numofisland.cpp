#include<iostream>
#include<queue>
using namespace std;
int dirx[8]={1,-1,0,0,1,1,-1,-1};
int diry[8]={0,0,1,-1,1,-1,1,-1};
int main(){//4963
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int w,h;
    while(cin>>w>>h){
        if(w==0 && h==0) break;
        int cnt=0;
        int arr[h][w];
        bool visited[h][w];
        for(int i=0; i<h; ++i){
            for(int j=0; j<w; ++j){
                cin>>arr[i][j];
                visited[i][j]=false;
            }
        }
        queue< pair<int,int> > qu;
        for(int j=0; j<h; ++j){
            for(int k=0; k<w; ++k){
                if(visited[j][k] || !arr[j][k]) continue;
                qu.push({j,k});
                visited[j][k]=true;
                while(!qu.empty()){
                    
                    int x = qu.front().first;
                    int y = qu.front().second;
                    qu.pop();
                    for(int i=0; i<8; ++i){
                        int nx=x+dirx[i];
                        int ny=y+diry[i];
                        if(nx>=h || nx<0) continue;
                        if(ny>=w || ny<0) continue;
                        if(visited[nx][ny] || !arr[nx][ny]) continue;
                        qu.push({nx,ny});
                        visited[nx][ny]=true;
                    }
                }
                ++cnt;
            }
        }
        cout<<cnt<<'\n';
    }
}