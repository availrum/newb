#include<iostream>
#include<vector>
#include<stack>
using namespace std;
const int max_int=2147483647;
int N,M, min_cnt=max_int;
struct component{
    int x;
    int y;
    char c;
};
void check(vector<vector<vector<pair<int,int>>>>& cctv, vector<pair<int,int>>& pos, vector<vector<char>> board, int num){
    if(num==pos.size()){
        // cout<<'\n';
        int cnt=0;
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                // cout<<board[i][j]<<' ';
                if(board[i][j]=='0') ++cnt;
            }
            // cout<<'\n';
        }
        min_cnt=min(min_cnt,cnt);
        return;
    }
    int x=pos[num].first;
    int y=pos[num].second;
    for(int j=0; j<cctv[board[x][y]-'0'].size(); ++j){
        stack<component> st;
        for(int k=0; k<cctv[board[x][y]-'0'][j].size(); ++k){
            for(int l=1; l<=max(N,M); ++l){
                int nx=x+l*cctv[board[x][y]-'0'][j][k].first;
                int ny=y+l*cctv[board[x][y]-'0'][j][k].second;
                if(nx<0 || nx>=N) break;
                if(ny<0 || ny>=M) break;
                if(board[nx][ny]=='6') break;
                if(board[nx][ny]=='0'){
                    st.push({nx,ny,board[nx][ny]});
                    board[nx][ny]='#';
                }
            }
        }
        check(cctv,pos,board,num+1);
        while(!st.empty()){
            int nx=st.top().x;
            int ny=st.top().y;
            char nc=st.top().c;
            st.pop();
            board[nx][ny]=nc;
        }
    }
}
int main(){ //15683
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    vector<vector<vector<pair<int,int>>>> cctv(7);
    // cctv번호, 감시하는 방향루트(오른쪽만,위만,... ,왼위오,위오아,... ), 해당루트의 cctv가 동시에 감시하는 방향
    cctv[1].push_back(vector<pair<int,int>>(1,{0,1}));
    cctv[1].push_back(vector<pair<int,int>>(1,{1,0}));
    cctv[1].push_back(vector<pair<int,int>>(1,{0,-1}));
    cctv[1].push_back(vector<pair<int,int>>(1,{-1,0}));

    cctv[2].push_back(vector<pair<int,int>>(1,{-1,0}));
    cctv[2][0].push_back({1,0});
    cctv[2].push_back(vector<pair<int,int>>(1,{0,-1}));
    cctv[2][1].push_back({0,1});

    cctv[3].push_back(vector<pair<int,int>>(1,{-1,0}));
    cctv[3][0].push_back({0,1});
    cctv[3].push_back(vector<pair<int,int>>(1,{0,1}));
    cctv[3][1].push_back({1,0});
    cctv[3].push_back(vector<pair<int,int>>(1,{1,0}));
    cctv[3][2].push_back({0,-1});
    cctv[3].push_back(vector<pair<int,int>>(1,{0,-1}));
    cctv[3][3].push_back({-1,0});

    cctv[4].push_back(vector<pair<int,int>>(1,{-1,0}));
    cctv[4][0].push_back({0,1});
    cctv[4][0].push_back({1,0});
    cctv[4].push_back(vector<pair<int,int>>(1,{0,1}));
    cctv[4][1].push_back({1,0});
    cctv[4][1].push_back({0,-1});
    cctv[4].push_back(vector<pair<int,int>>(1,{1,0}));
    cctv[4][2].push_back({0,-1});
    cctv[4][2].push_back({-1,0});
    cctv[4].push_back(vector<pair<int,int>>(1,{0,-1}));
    cctv[4][3].push_back({-1,0});
    cctv[4][3].push_back({0,1});

    cctv[5].push_back(vector<pair<int,int>>(1,{-1,0}));
    cctv[5][0].push_back({0,1});
    cctv[5][0].push_back({1,0});
    cctv[5][0].push_back({0,-1});

    // for(int i=1; i<6; ++i){
    //     cout<<"CCTV"<<i<<'\n';
    //     for(int j=0; j<cctv[i].size(); ++j){
    //         cout<<"ROOT"<<j+1<<'\n';
    //         for(int k=0; k<cctv[i][j].size(); ++k){
    //             cout<<cctv[i][j][k].first<<' '<<cctv[i][j][k].second<<'\n';
    //         }
    //     }
    //     cout<<'\n';
    // }
    // cout<<cctv[2][0][1].first<<' '<<cctv[2][0][1].second<<'\n';
    vector<vector<char>> board(N, vector<char>(M,'0'));
    vector<pair<int,int>> pos;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cin>>board[i][j];
            if(board[i][j]=='0' || board[i][j]=='6') continue;
            pos.push_back({i,j});
        }
    }
    check(cctv,pos,board,0);
    cout<<min_cnt<<'\n';
} 