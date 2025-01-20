#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){//17834
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    int visited[N+1]={0,};
    vector<int> vec[N+1];
    int u, v;
    for(int i=0; i<M; ++i){
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    queue<int> qu;
    bool flag=false;
    vector<int> cntodd,cnteven;

    qu.push(1);
    visited[1]=1;
    cntodd.push_back(1);
    while(!qu.empty()){
        int x=qu.front();
        // cout<<x<<'\n';
        qu.pop();
        for(int j=0; j<vec[x].size(); ++j){
            if(!visited[vec[x][j]]){
                if(visited[x]==2){
                    visited[vec[x][j]]=1;
                    cntodd.push_back(vec[x][j]);
                }
                else if(visited[x]==1){
                    visited[vec[x][j]]=2;
                    cnteven.push_back(vec[x][j]);
                }
                qu.push(vec[x][j]);
            }
            else if(visited[x]==visited[vec[x][j]]){
                flag=true;
                break;
            }
        }
        if(flag) break;
    }
    if(flag){
        cout<<"0"<<'\n';
        return 0;
    }
    int sol=0;
    for(int i=1; i<=N; ++i){
        if(visited[i]==1) sol+=cnteven.size();
        else sol+=cntodd.size();
    }
    cout<<sol<<'\n';
}
