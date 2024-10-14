#include<iostream>
#include<vector>
using namespace std;
int diameter,N;
vector<pair<int,int>> vec[10002];
int dfs(int x, int cost, bool *visited){
    if(diameter<cost) diameter=cost;
    visited[x]=true;
    for(int i=0; i<vec[x].size(); ++i){
        if(!visited[vec[x][i].first]){
            dfs(vec[x][i].first, cost+vec[x][i].second, visited);
        }
    }
    return 0;
}
int main(){//1967
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    
    int st,ed,val;
    for(int i=0; i<N-1; ++i){
        cin>>st>>ed>>val;
        vec[st].push_back({ed,val});
        vec[ed].push_back({st,val});
        
        if(!vec[ed].size()) vec[ed].push_back({st,val});
        else{
            int flag=0;
            for(int j=0; j<vec[ed].size(); ++j){
                if(vec[ed][j].first==st){
                    flag=1;
                    if(vec[ed][j].second<val) vec[ed][j].second=val;
                    break;
                }
            }
            if(flag==0) vec[ed].push_back({st,val});
        }
    }
    for(int i=N; i>=1; --i){
        bool visited[N+1]={0,};
        dfs(i, 0, visited);
    }
    cout<<diameter<<'\n';
}