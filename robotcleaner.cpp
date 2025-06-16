#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int dirx[4]={-1,0,1,0};
int diry[4]={0,1,0,-1};
int cnt=0;
void move_robot(vector<vector<int>>& arr, int x, int y, int dir){
    // cout<<x<<' '<<y<<'\n';
    int n=arr.size();
    int m=arr[0].size();
    if(arr[x][y]==0){
        ++cnt;
        arr[x][y]=-1;
    }
    bool flag=false;
    for(int i=0; i<4; ++i){
        int nx=x+dirx[i];
        int ny=y+diry[i];
        if(nx<0 || nx>=n) continue;
        if(ny<0 || ny>=m) continue;
        if(arr[nx][ny]==0){
            flag=true;
        }
    }
    if(!flag){
        int nx=x-dirx[dir];
        int ny=y-diry[dir];
        if(!(nx<0 || nx>=n || ny<0 || ny>=m) && arr[nx][ny]!=1){
            move_robot(arr,nx,ny,dir);
        }
        else return;
    }
    else{
        while(true){
            --dir;
            if(dir<0) dir+=4;
            int nx=x+dirx[dir];
            int ny=y+diry[dir];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(arr[nx][ny]==0){
                move_robot(arr,nx,ny,dir);
                return;
            }
        }
    }
}
int main(){//14503
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    vector<vector<int>> room(N);
    int r,c,d;
    cin>>r>>c>>d;
    int tmp;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cin>>tmp;
            room[i].push_back(tmp);
        }
    }
    move_robot(room,r,c,d);
    cout<<cnt<<'\n';
}