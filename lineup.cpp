#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
using namespace std;
int main(){//2252
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    int a,b;
    vector<int> vec[N+1];
    unordered_map<int,int> check;
    for(int i=0; i<M; ++i){
        cin>>a>>b;
        vec[a].push_back(b);
        ++check[b];
    }
    queue<int> qu;
    for(int i=1; i<=N; ++i){
        if(!check[i]){
            qu.push(i);
        }
    }
    while(!qu.empty()){
        int x=qu.front();
        qu.pop();
        for(int i=0; i<vec[x].size(); ++i){
            if(check[vec[x][i]]==1){
                qu.push(vec[x][i]);
            }
            --check[vec[x][i]];
        }
        cout<<x;
        if(!qu.empty()) cout<<' ';
        else cout<<'\n';
    }
}