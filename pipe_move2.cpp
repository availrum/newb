#include<iostream>
#include<vector>
#define ll long long int
using namespace std;
int main(){ //17069
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N,t;
    cin>>N;
    vector<vector<ll>> minimap(N,vector<ll>(N,0));
    vector<vector<vector<ll>>> cnt(N,vector<vector<ll>>(N,vector<ll>(3,0)));

    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin>>minimap[i][j];
        }
    }
    cnt[0][1][0]=1;
    for(int i=0; i<N; ++i){
        if(i==0){
            for(int j=2; j<N; ++j){
                if(minimap[i][j]==1) continue;
                cnt[i][j][0]+=cnt[i][j-1][0];
            }
            continue;
        }
        for(int j=1; j<N; ++j){
            if(minimap[i][j]==1) continue;
            cnt[i][j][0]+=(cnt[i][j-1][0])+(cnt[i][j-1][1]);
            if(minimap[i][j-1]!=1 && minimap[i-1][j]!=1) cnt[i][j][1]+=(cnt[i-1][j-1][0])+(cnt[i-1][j-1][1])+(cnt[i-1][j-1][2]);
            cnt[i][j][2]+=(cnt[i-1][j][1])+(cnt[i-1][j][2]);
        }
    }
    ll sol=0;
    for(int i=0; i<3; ++i){
        sol+=cnt[N-1][N-1][i];
    }
    cout<<sol<<'\n';
}