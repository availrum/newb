#include<iostream>
#include<vector>
using namespace std;
int main(){//12865
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,K;
    cin>>N>>K;
    int W[N+1]={0,}, V[N+1]={0,};//, mass[N+1][N+1]={0,},mval[N+1][N+1]={0,};
    for(int i=1; i<=N; ++i){
        cin>>W[i]>>V[i];
        // mass[0][i]=0;
        // mval[0][i]=0;
    }
    vector<vector<int>> mval(N+1,vector<int>(K+1,0));
    for(int i=1; i<=N; ++i){
        // for(int j=mval.size()-1; j>=0; --j){
        //     if(mval[j]+W[i]<=K){
        //         if()
        //     }
        for(int j=0; j<=K; ++j){
            if(j>=W[i]) mval[i][j]=max(mval[i-1][j], mval[i-1][j-W[i]]+V[i]);
            else mval[i][j]=mval[i-1][j];
        }
        // for(int j=i; j>=0; --j){

            // if(mass[i-1][j]+W[i]<=K){
            // //  && mval[j]+V[i]>mval[i]){
            //     mass[i][j]=mass[i-1][j]+W[i];
            //     mval[i][j]=mval[i-1][j]+V[i];
            // }
            // else{
            //     mass[i][j]=mass[i-1][j];
            //     mval[i][j]=mval[i-1][j];
            // }
        // }
        // cout<<mval[i][i]<<'\n';
    }
    cout<<mval[N][K]<<'\n';
    // int max=0;
    // for(int i=1; i<=N; ++i) cout<<mval[3][i]<<'\n';
    // if(max<mval[N][i]) max=mval[N][i];
    // cout<<max<<'\n';
}