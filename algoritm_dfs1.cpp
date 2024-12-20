#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int num[100001];
vector<vector<int>> vec(100001);
int cnt=1;
void dfs(int N){
    num[N]=cnt;
    for(int i=0; i<vec[N].size(); ++i){
        if(num[vec[N][i]]) continue;
        ++cnt;
        dfs(vec[N][i]);
    }
}
int main(){//24479
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, R;
    cin>>N>>M>>R;
    int u,v;
    for(int i=0; i<M; ++i){
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    for(int i=1; i<=N; ++i){
        sort(vec[i].begin(),vec[i].end());
    }
    dfs(R);
    // while(!st.empty()){
    //     int tmpx=st.top();
    //     st.pop();
    //     for(int i=vec[tmpx].size()-1; i>=0; --i){
    //         if(!num[vec[tmpx][i]]){
    //             st.push(vec[tmpx][i]);
    //             num[vec[tmpx][i]]=++cnt;
    //             continue;
    //         }
    //     }
    // }
    for(int i=1; i<=N; ++i){
        cout<<num[i]<<'\n';
    }
    
}