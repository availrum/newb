#include<iostream>
#include<vector>
using namespace std;
int main(){ //2167
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M,t;
    cin>>N>>M;
    vector<vector<int>> arrsum(N,vector<int>(M,0));
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cin>>t;
            if(i==0 && j==0) arrsum[i][j]=t;
            else if(j!=0) arrsum[i][j]=arrsum[i][j-1]+t;
            else arrsum[i][j]=arrsum[i-1][M-1]+t;
        }
    }
    int K;
    cin>>K;
    // for(int i=0; i<N; ++i){
    //     for(int j=0; j<M; ++j) cout<<arrsum[i][j]<<' ';
    //     cout<<'\n';
    // }
    int x1,x2,y1,y2;
    for(int i=0; i<K; ++i){
        cin>>x1>>y1>>x2>>y2;
        int val=0;
        for(int j=x1-1; j<x2; ++j){
            if(y1>1) val+=(arrsum[j][y2-1]-arrsum[j][y1-2]);
            else if(j!=0 && y1==1) val+=(arrsum[j][y2-1]-arrsum[j-1][M-1]);
            else val+=arrsum[j][y2-1];
        }
        cout<<val<<'\n';
    }
}