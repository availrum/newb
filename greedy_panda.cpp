#include<iostream>
#include<vector>
using namespace std;
int dirx[4]={0,1,0,-1};
int diry[4]={1,0,-1,0};
int max_cnt=0;
int dfs(int x, int y, vector<vector<int>>& forest, vector<vector<int>>& cnt){
    if(cnt[x][y]>=0) return 1+cnt[x][y];
    int n=forest.size();
    // for(int i=0; i<n; ++i){
    //     for(int j=0; j<n; ++j){
    //         cout<<cnt[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // } cout<<'\n';
    int tmp=0;
    for(int i=0; i<4; ++i){
        int nx=x+dirx[i];
        int ny=y+diry[i];
        if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
        else if(forest[x][y]>=forest[nx][ny]) continue;
        tmp=max(tmp,dfs(nx,ny,forest,cnt));
    }
    cnt[x][y]=tmp;
    return tmp+1;
}
int main(){ //1937
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,t;
    cin>>n;
    vector<vector<int>> forest(n, vector<int>(n,0)), cnt(n, vector<int>(n,-1));
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin>>forest[i][j];
        }
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            max_cnt=max(max_cnt,dfs(i,j,forest,cnt));
        }
    }
    // for(int i=0; i<n; ++i){
    //     for(int j=0; j<n; ++j){
    //         cout<<cnt[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    cout<<max_cnt<<'\n';
}