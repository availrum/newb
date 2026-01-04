#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int main(){ //1325
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    vector<vector<int>> com(N+1);
    int A,B;
    for(int i=0; i<M; ++i){
        cin>>A>>B;
        com[B].push_back(A);
    }
    queue<int> qu;
    int max_connect=0;
    vector<pair<int,int>> link_com;
    for(int i=1; i<=N; ++i){
        qu.push(i);
        vector<bool> trust(N+1,false);
        trust[i]=true;
        while(!qu.empty()){
            int x=qu.front();
            qu.pop();
            for(int j=0; j<com[x].size(); ++j){
                if(trust[com[x][j]]) continue;
                trust[com[x][j]]=true;
                qu.push(com[x][j]);
            }
        }
        int cnt=0;
        for(int j=1; j<=N; ++j) if(trust[j]) ++cnt;
        if(max_connect>cnt) continue;
        else if(max_connect==cnt) link_com.push_back({cnt,i});
        else{
            max_connect=cnt;
            link_com.clear();
            link_com.push_back({cnt,i});
        }
    }
    sort(link_com.begin(), link_com.end());
    for(int i=0; i<link_com.size(); ++i){
        if(i!=0) cout<<' ';
        cout<<link_com[i].second;
    }
    cout<<'\n';
    // cout<<cnt<<'\n';
}