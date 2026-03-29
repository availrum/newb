#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int dirx[8]={-1,-1,-1,0,0,1,1,1};
int diry[8]={-1,-0,1,-1,1,-1,0,1};
struct val{
    int x;
    int y;
    int cost;
};
int main(){ //16235
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M,K;
    cin>>N>>M>>K;
    vector<vector<int>> A(N,vector<int>(N,0)), nutrient(N, vector<int>(N,5));
    vector<vector<vector<int>>> field(N,vector<vector<int>>(N));
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j) cin>>A[i][j];
    }
    for(int i=0; i<M; ++i){
        int x,y,z;
        cin>>x>>y>>z;
        field[x-1][y-1].push_back(z);
    }
    for(int year=0; year<K; ++year){
        queue<val> dead_tree;
        for(int i=0; i<N; ++i){ //봄
            for(int j=0; j<N; ++j){
                sort(field[i][j].begin(),field[i][j].end());
                queue<int> qu;
                for(int k=0; k<field[i][j].size(); ++k){
                    if(field[i][j][k]>nutrient[i][j]){
                        dead_tree.push({i,j,field[i][j][k]/2});
                    }
                    else{
                        qu.push(field[i][j][k]+1);
                        nutrient[i][j]-=field[i][j][k];
                    }
                }
                vector<int> tmp;
                while(!qu.empty()){
                    tmp.push_back(qu.front());
                    qu.pop();
                }
                field[i][j]=tmp;
            }
        }
        while(!dead_tree.empty()){ //여름
            int x=dead_tree.front().x;
            int y=dead_tree.front().y;
            int val=dead_tree.front().cost;
            dead_tree.pop();
            nutrient[x][y]+=val;
        }
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                for(int k=0; k<field[i][j].size(); ++k){
                    if(field[i][j][k]%5==0){
                        for(int l=0; l<8; ++l){
                            int nx=i+dirx[l];
                            int ny=j+diry[l];
                            if(nx<0 || nx>=N || ny<0 || ny>=N) continue;
                            field[nx][ny].push_back(1);
                        }
                    }
                }
            }
        }

        for(int i=0; i<N; ++i){ //겨울
            for(int j=0; j<N; ++j){
                nutrient[i][j]+=A[i][j];
            }
        }
    }
    int cnt=0;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cnt+=field[i][j].size();
        }
    }
    cout<<cnt<<'\n';
}