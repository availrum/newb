#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
bool visited[101][101];
bool graph[101][101];

int main(){//2178
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M,tmp;
    map<vector<int>, int> cnt;
    queue<int> bfsx,bfsy;
    string st;
    cin>>N>>M;
    for(int i=0; i<N; i++){//입력
        cin>>st;
        for(int j=0; j<M; j++){
            if(st[j]==1) continue;
            graph[i][j]=st[j]-48;
        }
        // cout<<'\n';
    }
        visited[0][0]=true;
        bfsx.push(0);
        bfsy.push(0);
        cnt[{0,0}]++;
        while(!bfsx.empty()){
            int x=bfsx.front();
            int y=bfsy.front();
            // cout<<x<<' '<<y<<'\n';
            // visited[x][y]=true;
            bfsx.pop();
            bfsy.pop();
            if(x==N-1 && y==M-1) break;
            for(int i=-1; i<=1; i++){
                if(x+i<0 || x+i>N-1) continue;
                // cout<<x+i<<'\n';
                for(int j=-1; j<=1; j++){
                    if(visited[x+i][y+j]==true) continue;
                    if(graph[x+i][y+j]==false) continue;
                    if(i!=0 && j!=0) continue;
                    if(y+j<0 || y+j>M-1) continue;
                    //     cout<<visited[x+i][y+j]<<' '<<graph[x+i][y+j]<<'\n';
                    // cout<<x+i<<", "<<y+j<<'\n';
                    //  && (graph[x+i][y+j]==true)){
                    if(cnt[{x+i,y+j}]!=0 && cnt[{x+i,y+j}]<cnt[{x,y}]+1) continue;
                    visited[x+i][y+j]=true;
                    bfsx.push(x+i);
                    bfsy.push(y+j);
                    cnt[{x+i,y+j}]=cnt[{x,y}]+1;
                    // if(x+i==N-1 && y+j==M-1) {
                    //     // cnt++;
                    //     // cout<<cnt[{x+i,y+j}]<<'\n';
                    //     // return 0;
                    // }
                        
                    // }
                    // else continue;
                    // if((visited[x+i][y+j]==true) || (graph[x+i][y+j]==false)) continue;
                }
            }
            // cout<<'\n';
            // cnt++;
            // cout<<bfsx.front()<<' '<<bfsy.front()<<'\n';
        }
    cout<<cnt[{N-1,M-1}]<<'\n';
    // for(int i=0; i<N; i++){
    //     for(int j=0; j<M; j++){
    //         cout<<graph[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    //     cout<<'\n';
    // for(int i=0; i<N; i++){
    //     for(int j=0; j<M; j++){
    //         cout<<visited[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }

    return 0;
}//256 128 64 32 16 8 4 2 1