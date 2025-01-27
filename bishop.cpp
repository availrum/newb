#include<iostream>
#include<vector>
using namespace std;
int chessboard[11][11];
bool diagonal1[21];
bool diagonal2[21];
void chess(vector<pair<int,int>> candi, int n, int sz, int maxbishop, int& cnt){
    int candisize=candi.size();
    if(cnt >= maxbishop+candisize-n) return;
    for(int i=n; i<candisize; ++i){
        int x=candi[i].first;
        int y=candi[i].second;
        if(diagonal1[sz-1+y-x]) continue;
        if(diagonal2[x+y]) continue;
        diagonal1[sz-1+y-x]=true;
        diagonal2[x+y]=true;
        chess(candi,i+1,sz,maxbishop+1,cnt);
        diagonal1[sz-1+y-x]=false;
        diagonal2[x+y]=false;
    }
    if(cnt<maxbishop){
        cnt=maxbishop;
    }
}
int main(){//1799
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    vector<pair<int,int>> candiW ,candiB;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin>>chessboard[i][j];
            if(chessboard[i][j]==1){
                if((i+j)%2==0) candiB.push_back({i,j});
                else candiW.push_back({i,j});
            }
        }
    }
    int cntB=0,cntW=0;
    chess(candiB,0,N,0,cntB);
    chess(candiW,0,N,0,cntW);
    int cnt=cntB+cntW;
    cout<<cnt<<'\n';
}