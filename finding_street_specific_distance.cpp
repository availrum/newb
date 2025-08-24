#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){ //18352
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, K, X;
    cin>>N>>M>>K>>X;
    vector<vector<int>> road(N+1);

    for(int i=0; i<M; ++i){
        int A,B;
        cin>>A>>B;
        road[A].push_back(B);
    }

    int dist[N+1];
    for(int i=0; i<=N; ++i) dist[i]=2147483647;
    dist[X]=0;

    queue<int> qu;
    qu.push(X);
    while(!qu.empty()){
        int t=qu.front();
        qu.pop();
        for(int i=0; i<road[t].size(); ++i){
            if(dist[t]+1<dist[road[t][i]]){
                qu.push(road[t][i]);
                dist[road[t][i]]=dist[t]+1;
            }
        }
    }
    vector<int> sol;
    for(int i=1; i<=N; ++i){
        if(i==X || dist[i]!=K) continue;
        sol.push_back(i);
    }
    if(!sol.size()) cout<<"-1"<<'\n';
    else{
        for(int i=0; i<sol.size(); ++i){
            cout<<sol[i]<<'\n';
        }
    }
}