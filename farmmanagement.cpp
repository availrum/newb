#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
int dirx[8]={1,-1,0,0,1,1,-1,-1};
int diry[8]={0,0,1,-1,1,-1,1,-1};
struct tup{
    int x;
    int y;
    int z;
    bool operator< (const tup& other) const{
        return z>other.z;
    }
};
int main(){//1245
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    int arr[N][M];
    bool visited[N][M];
    vector<tup> vec;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cin>>arr[i][j];
            visited[i][j]=false;
            if(arr[i][j]) vec.push_back({i,j,arr[i][j]});
        }
    }
    queue<pair<int,int>> qu;
    int cnt=0;
    sort(vec.begin(),vec.end());
    // for(int i=0; i<vec.size(); ++i){
    //     cout<<vec[i].x<<' '<<vec[i].y<<' '<<vec[i].z<<'\n';
    // }
    for(int idx=0; idx<vec.size(); ++idx){
        int i=vec[idx].x;
        int j=vec[idx].y;
        if(visited[i][j]) continue;
        if(!arr[i][j]) continue;
        qu.push({i,j});
        visited[i][j]=true;
        while(!qu.empty()){
            int x=qu.front().first;
            int y=qu.front().second;
            qu.pop();
            for(int k=0; k<8; ++k){
                int nx=x+dirx[k];
                int ny=y+diry[k];
                if(nx>=N || nx<0) continue;
                if(ny>=M || ny<0) continue;
                if(visited[nx][ny]) continue;
                if(!arr[nx][ny]) continue;
                if(arr[x][y]-arr[nx][ny]<0) continue;
                qu.push({nx,ny});
                visited[nx][ny]=true;
            }
        }
        // cout<<i<<' '<<j<<'\n';
        ++cnt;
    }
    cout<<cnt<<'\n';
}