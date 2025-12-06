#include<iostream>
#include<vector>
using namespace std;
int dirx[3]={0,1,1};
int diry[3]={1,1,0};
int main(){ //11048
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    vector<vector<int>> maze(N,vector<int>(M,0)), candi(N,vector<int>(M,0));
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cin>>candi[i][j];
        }
    }
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            if(i==0){
                if(j==0) maze[i][j]=candi[i][j];
                else maze[i][j]=maze[i][j-1]+candi[i][j];
            }
            else if(j==0) maze[i][j]=maze[i-1][j]+candi[i][j];
            else maze[i][j]=max( max(maze[i][j-1],maze[i-1][j]), maze[i-1][j-1] )+candi[i][j];
        }
    }
    cout<<maze[N-1][M-1]<<'\n';
}