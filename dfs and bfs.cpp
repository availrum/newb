#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
bool visited_dfs[1001];
bool visited_bfs[1001];
vector<int> graphd[10001];
vector<int> graphb[10001];

void dfs(int N){
    visited_dfs[N]=true;
    for(int i=0; i<graphd[N].size(); i++){
        int y=graphd[N][i];
        if(!visited_dfs[y]){
            cout<<y<<' ';
            dfs(y);
        }
    }
}
void bfs(int N){
    queue<int> qu;
    qu.push(N);
    visited_bfs[N]=true;
    while(!qu.empty()){
        int x=qu.front();
        cout<< x <<' ';
        qu.pop();
        for(int i=0; i<graphb[x].size(); i++){
            int y =graphb[x][i];
            if(!visited_bfs[y]){
                qu.push(y);
                visited_bfs[y]=true;
            }
        }
    }

}
int main(){
    int n,m,v,a,b,sd,sb;
    cin>>n>>m>>v;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        graphd[a].push_back(b);
        graphd[b].push_back(a);

        graphb[a].push_back(b);
        graphb[b].push_back(a);
    }
    
    for(int i=0; i<m; i++){
        sort(graphd[i].begin(),graphd[i].end());
        sort(graphb[i].begin(),graphb[i].end());
    }
    cout<<v<<' ';
    dfs(v);
    cout<<'\n';
    bfs(v);
    cout<<'\n';
}