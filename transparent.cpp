#include<iostream>
using namespace std;
int main(){ //1531
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    int picture[100][100];
    for(int i=0; i<100; ++i){
        for(int j=0; j<100; ++j){
            picture[i][j]=0;
        }
    }
    for(int i=0; i<N; ++i){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        for(int j=x1-1; j<x2; ++j){
            for(int k=y1-1; k<y2; ++k){
                ++picture[j][k];
            }
        }
    }
    int cnt=0;
    for(int i=0; i<100; ++i){
        for(int j=0; j<100; ++j){
            if(picture[i][j]>M) ++cnt;
        }
    }
    cout<<cnt<<'\n';
}