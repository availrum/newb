#include<iostream>
#include<vector>
using namespace std;
int dirx[2]={0,1};
int diry[2]={1,0};
int main(){ //10164
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M,K;
    cin>>N>>M>>K;
    vector<vector<int>> cnt(N,vector<int>(M,0));
    int idx=1;
    int x=N,y=M;
    bool flag=false;
    cnt[0][0]=1;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            if(idx==K){
                x=i,y=j;
                flag=true;
                break;
            }
            for(int k=0; k<2; ++k){
                int nx=i+dirx[k];
                int ny=j+diry[k];
                if(nx>=N || ny>=M) continue;
                cnt[nx][ny]+=cnt[i][j];
            }
            ++idx;
        }
        if(flag) break;
    }
    for(int i=x; i<N; ++i){
        for(int j=y; j<M; ++j){
            if(i==x && j==y) continue;
            cnt[i][j]=0;
        }
    }
    for(int i=x; i<N; ++i){
        for(int j=y; j<M; ++j){
            for(int k=0; k<2; ++k){
                int nx=i+dirx[k];
                int ny=j+diry[k];
                if(nx>=N || ny>=M) continue;
                cnt[nx][ny]+=cnt[i][j];
            }
        }
    }
    // for(int i=0; i<N; ++i){
    //     for(int j=0; j<M; ++j){
    //         cout<<cnt[i][j];
    //     }cout<<'\n';
    // }
    cout<<cnt[N-1][M-1]<<'\n';
}