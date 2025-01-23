#include<iostream>
#include<vector>
using namespace std;
int main(){//11657
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    vector<pair<int,int>> bus[N+1];
    long long int INF=100000000001;
    long long int dist[N+1];
    for(int i=0; i<=N; ++i){
        dist[i]=INF;
    }
    int A,B,C;
    for(int i=0; i<M; ++i){
        cin>>A>>B>>C;
        bus[A].push_back({B,C});
    }
    dist[1]=0;
    bool flag=false;
    for(int iter=1; iter<=N; ++iter){
        flag=false;
        for(int i=1; i<=N; ++i){
            if(dist[i]==INF) continue;
            for(int j=0; j<bus[i].size(); ++j){
                if(dist[i]+bus[i][j].second < dist[bus[i][j].first]){
                    dist[bus[i][j].first]=dist[i]+bus[i][j].second;
                    flag=true;
                }
            }
        }
        if(!flag) break;
    }
    if(flag) cout<<"-1"<<'\n';
    else{
        for(int i=2; i<=N; ++i){
            if(dist[i]!=INF) cout<<dist[i]<<'\n';
            else cout<<"-1"<<'\n';
        }
    }
}