#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
int main(){//14567
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;int course[N+1];
    vector<int> vec[N+1];
    unordered_map<int,int> check, semester;
    int a,b;
    for(int i=0; i<M; ++i){
        cin>>a>>b;
        vec[a].push_back(b);
        ++check[b];
    }
    queue<int> qu;
    for(int i=1; i<=N; ++i){
        if(!check[i]){
            qu.push(i);
            semester[i]=1;
        }
    }
    while(!qu.empty()){
        int x=qu.front();
        int y=qu.front();
        qu.pop();
        for(int i=0; i<vec[x].size(); ++i){
            if(check[vec[x][i]]==1){
                qu.push(vec[x][i]);
                if(semester[vec[x][i]]==0 || semester[vec[x][i]]>semester[x]+1){
                    semester[vec[x][i]]=semester[x]+1;
                }
            }
            --check[vec[x][i]];
        }
    }
    int sol;
    for(int i=1; i<=N; ++i){
        cout<<semester[i];
        if(i!=N) cout<<' ';
    }
    cout<<'\n';
}