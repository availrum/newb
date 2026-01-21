#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
bool check(vector<vector<bool>>& used){
    bool flag=false;
    int total_bingo=0;
    for(int i=0; i<5; ++i){
        int cnt=0;
        for(int j=0; j<5; ++j){
            if(used[i][j]) ++cnt;
        }
        if(cnt==5) ++total_bingo;
    }
    for(int j=0; j<5; ++j){
        int cnt=0;
        for(int i=0; i<5; ++i){
            if(used[i][j]) ++cnt;
        }
        if(cnt==5) ++total_bingo;
    }

    for(int i=0; i<5; ++i){
        if(!used[i][i]) break;
        if(i==4) ++total_bingo;
    }
    for(int i=0; i<5; ++i){
        if(!used[i][4-i]) break;
        if(i==4) ++total_bingo;
    }
    // cout<<total_bingo<<'\n';
    if(total_bingo>=3) flag=true;
    return flag;
}
int main(){ //2578
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,t;
    vector<vector<int>> board(6,vector<int>(6,0));
    unordered_map<int,pair<int,int>> log;
    for(int i=0; i<5; ++i){
        for(int j=0; j<5; ++j){
            cin>>board[i][j];
            log[board[i][j]]={i,j};
        }
    }
    int complete=0;
    vector<vector<bool>> used(6,vector<bool>(6,false));
    for(int i=0; i<5; ++i){
        for(int j=0; j<5; ++j){
            int t;
            cin>>t;
            int x=log[t].first;
            int y=log[t].second;
            used[x][y]=true;
            
            if(complete==0 && check(used)) complete=5*i+(j+1);
        }
    }
    cout<<complete<<'\n';
}