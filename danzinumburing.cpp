#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
int dirx[4]={-1,1,0,0};
int diry[4]={0,0,-1,1};
int graph[26][26];
bool visited[26][26];
// int sol[135];
struct Vector2D{
    int i,j;
};
int main(){//2667
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    queue<Vector2D> qu;
    vector<int> sol;
    int N,cnt=0;
    string st;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>st;
        for(int j=0; j<N; j++){
            graph[i][j]=st[j]-48;
            // if(tmp==0){
            //     if(graph[i][j]){
            //         qu.push({i,j});
            //         visited[i][j]=true;
            //         tmp++;
            //     }
            // }
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(graph[i][j]==1){ 
                int num=0;
                // if(tmp==1) {
                //     num++;
                // }
                if(!visited[i][j]){//조건확인
                // visited[i][j]=true;
                    // if(tmp==1) tmp--;
                    // else 
                    qu.push({i,j});
                    visited[i][j]=true;
                    while(!qu.empty()){
                        Vector2D tmpv=qu.front();
                        qu.pop();
                        num++;
                        for(int x1=0; x1<4; x1++){
                            int xt=tmpv.i+dirx[x1];
                            int yt=tmpv.j+diry[x1];
                            if(xt<0 || yt<0 || xt>N-1 || yt>N-1) continue;
                            if(graph[xt][yt]==0) continue;
                            if(!visited[xt][yt]){
                                visited[xt][yt]=1;
                                Vector2D tm;
                                tm.i=xt;
                                tm.j=yt;
                                qu.push(tm);
                                // num++;
                            }
                        }
                    }
                // cout<<i<<' '<<num<<' '<<j<<'\n'<<'\n';
                sol.push_back(num);
                cnt++;
                }
                // if(num==0) num++;
                // if(num==0) cnt++;
            }
        }
    }
    // cout<<'\n';
    // for(int i=0; i<N; i++){
    //     for(int j=0; j<N; j++){
    //         cout<<graph[i][j];
    //     }
    //     cout<<'\n';
    // }
    cout<<cnt<<'\n';
    sort(sol.begin(),sol.end());
    for(int i=0; i<sol.size(); i++){
        // if(i==0) cout<<sol[i]+1<<'\n';
        cout<<sol[i]<<'\n';
    }
    return 0;
}
