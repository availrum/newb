#include<iostream>
#include<vector>
#define ll long long int
using namespace std;
void dfs(ll n, ll w, vector<vector<ll>>& connect, vector<ll>& score, vector<ll>& visited){
    if(visited[n]) return;
    if(connect[n].size()==0){
        visited[n]=score[n]+w;
        return;
    }
    visited[n]=score[n]+w;
    for(int i=0; i<connect[n].size(); ++i){
        dfs(connect[n][i], visited[n], connect,score,visited);
    }
}
int main(){ //14267
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> connect(n+1);
    for(int i=1; i<=n; ++i){
        ll t;
        cin>>t;
        if(t!=-1) connect[t].push_back(i);
    }
    vector<ll> score(n+1,0), visited(n+1,0);
    for(int i=0; i<m; ++i){
        ll num,w;
        cin>>num>>w;
        score[num]+=w;
    }
    for(int i=1; i<=n; ++i){
        dfs(i, 0, connect,score,visited);
    }
    for(int i=1; i<=n; ++i){
        if(i!=1) cout<<' ';
        cout<<visited[i];
    } cout<<'\n';
}