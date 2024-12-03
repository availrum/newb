#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
using namespace std;
int main(){//31854
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    vector<int> vec[N*N+1];
    unordered_map<int,int> check;
    char st;
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=N-1; ++j){
            cin>>st;
            if(st=='<'){
                vec[N*(i-1)+j].push_back(N*(i-1)+j+1);
                ++check[N*(i-1)+j+1];
            }
            else{
                vec[N*(i-1)+j+1].push_back(N*(i-1)+j);
                ++check[N*(i-1)+j];
            }
        }
    }
    for(int i=1; i<=N-1; ++i){
        for(int j=1; j<=N; ++j){
            cin>>st;
            if(st=='<'){
                vec[N*(i-1)+j].push_back(N*i+j);
                ++check[N*i+j];
            }
            else{
                vec[N*i+j].push_back(N*(i-1)+j);
                ++check[N*(i-1)+j];
            }
        }
    }
    queue<int> qu;
    int sol[N+1][N+1];
    for(int i=1; i<=N*N; ++i){
        if(!check[i]){
            qu.push(i);
        }
        sol[(i-1)/N+1][(i-1)%N+1]=0;
    }
    int num=1;
    while(!qu.empty()){
        int x=qu.front();
        qu.pop();
        sol[(x-1)/N+1][(x-1)%N+1]=num;
        for(int i=0; i<vec[x].size(); ++i){
            if(check[vec[x][i]]==1){
                qu.push(vec[x][i]);
            }
            --check[vec[x][i]];
        }
        ++num;
    }
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=N; ++j){
            cout<<sol[i][j];
            if(j!=N) cout<<' ';
            else cout<<'\n';
        }
    }
}