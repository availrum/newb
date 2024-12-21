#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
int main(){//24445
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, R;
    cin>>N>>M>>R;
    int u,v;
    vector<vector<int>> vec(N+1);
    for(int i=0; i<M; ++i){
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    for(int i=1; i<=N; ++i){
        sort(vec[i].begin(),vec[i].end());
    }
    int num[N+1]={0,};
    queue<int> qu;
    qu.push(R);
    int cnt=1;
    num[R]=1;
    while(!qu.empty()){
        int tmpx=qu.front();
        qu.pop();
        for(int i=vec[tmpx].size()-1; i>=0; --i){
            if(!num[vec[tmpx][i]]){
                qu.push(vec[tmpx][i]);
                num[vec[tmpx][i]]=++cnt;
                continue;
            }
        }
    }
    for(int i=1; i<=N; ++i){
        cout<<num[i]<<'\n';
    }
    
}