#include <vector>
#include <iostream>
#include <queue>
using namespace std;
vector<int> graph[101];//행렬 양방향 확인
bool visited[101];
int cnt=0,chonsu=0;
int tmp=0;
int n,s1,s2,m;
int dfs(int N){
    tmp=0;
    if(chonsu!=0) return 0;
    visited[N]=true;
    for(int i=0; i<graph[N].size(); i++){
        if(graph[N][i]==s2){
            chonsu++;
            cnt++;
            return 0;
        }
    }
    for(int i=0; i<graph[N].size(); i++){
        int y=graph[N][i];
        if(!visited[y]){
            // cout<<"sd"<<y<<'\n';
            tmp=dfs(y);
            cnt-=tmp;
            cnt++;
            if(tmp==0) return 0;
        }
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int c1,c2;
    cin>>n;
    cin>>s1>>s2;
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>c1>>c2;
        graph[c1].push_back(c2);
        graph[c2].push_back(c1);
    }
    dfs(s1);
    if(chonsu==0){
        cout<<"-1"<<'\n';
    }
    else cout<<cnt<<'\n';

    // for(int i=1; i<=n; i++){
    //     cout<<i<<' ';
    //     for(int j=0; j<graph[i].size(); j++){
    //         cout<<graph[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    return 0;
}