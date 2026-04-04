#include<iostream>
#include<vector>
using namespace std;
int main(){ //1495
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,S,M,t;
    cin>>N>>S>>M;
    vector<vector<bool>> max_vol(N, vector<bool>(M+1,false));
    for(int i=0; i<N; ++i){
        cin>>t;
        if(i==0){
            if(S+t<=M) max_vol[0][S+t]=true;
            if(S-t>=0) max_vol[0][S-t]=true;
        }
        else{
            for(int j=0; j<=M; ++j){
                if(!max_vol[i-1][j]) continue;
                if(j+t<=M) max_vol[i][j+t]=true;
                if(j-t>=0) max_vol[i][j-t]=true;
            }
        }
    }
    int sol=-1;
    for(int i=0; i<=M; ++i){
        if(max_vol[N-1][i]) sol=max(sol,i);
    }
    cout<<sol<<'\n';
}