#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int dirx[4]={0,1,0,-1};
int diry[4]={1,0,-1,0};
int main(){ //3055
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int R,C;
    cin>>R>>C;
    vector<vector<char>> vec(R,vector<char>(C));
    pair<int,int> dochi, beaver;
    for(int i=0; i<R; ++i){
        string st;
        cin>>st;
        for(int j=0; j<st.length(); ++j){
            vec[i][j]=st[j];
            if(st[j]=='S') dochi={i,j};
            else if(st[j]=='D') beaver={i,j};
        }
    }
    vector<vector<pair<bool,int>>> visited(R,vector<pair<bool,int>>(C,{false,0}));
    queue<pair<int,int>> qu;
    qu.push(dochi);
    visited[dochi.first][dochi.second].first=true;
    int time=0;
    while(!qu.empty()){
        int x=qu.front().first;
        int y=qu.front().second;
        qu.pop();
        if(time<=visited[x][y].second){
            ++time;
            vector<vector<char>> tmp=vec;
            for(int i=0; i<R; ++i){
                for(int j=0; j<C; ++j){
                    if(vec[i][j]!='*') continue;
                    for(int k=0; k<4; ++k){
                        int ni=i+dirx[k];
                        int nj=j+diry[k];
                        if(ni<0 || ni>=R || nj<0 || nj>=C) continue;
                        else if(vec[ni][nj]=='X') continue;
                        else if(vec[ni][nj]=='D') continue;
                        tmp[ni][nj]='*';
                    }
                }
            }
            vec=tmp;
        }
        for(int i=0; i<4; ++i){
            int nx=x+dirx[i];
            int ny=y+diry[i];
            if(nx<0 || nx>=R || ny<0 || ny>=C) continue;
            else if(vec[nx][ny]=='X' || vec[nx][ny]=='*') continue;
            else if(visited[nx][ny].first) continue;
            qu.push({nx,ny});
            visited[nx][ny].first=true;
            visited[nx][ny].second=visited[x][y].second+1;
        }
    }
    if(!visited[beaver.first][beaver.second].first) cout<<"KAKTUS\n";
    else cout<<visited[beaver.first][beaver.second].second<<'\n';
    // for(int i=0; i<R; ++i){
    //     for(int j=0; j<C; ++j){
    //         cout<<visited[i][j].second;
    //     }
    //     cout<<'\n';
    // }
}