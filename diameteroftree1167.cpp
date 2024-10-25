#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int diameter,N;
vector<pair<int,int>> vec[100002];
int main(){//1167
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    
    int st,ed,val;
    for(int i=0; i<N; ++i){
        cin>>st;
        while(true){
            cin>>ed;
            if(ed==-1) break;
            cin>>val;
            vec[st].push_back({ed,val});
        }
    }
    queue<int> qu;
    int cost[100001]={0,};
    bool visited[100001]={0,};
    visited[1]=true;
    qu.push(1);
    int tmp=0;
    while(!qu.empty()){
        int x=qu.front();
        qu.pop();
        for(int i=0; i<vec[x].size(); ++i){
            if(visited[vec[x][i].first]) continue;
            if(cost[vec[x][i].first]<=cost[x]+vec[x][i].second){
                qu.push(vec[x][i].first);
                cost[vec[x][i].first]=cost[x]+vec[x][i].second;
                visited[vec[x][i].first]=true;
                if(cost[vec[x][i].first]>diameter){
                    diameter=cost[vec[x][i].first];
                    tmp=vec[x][i].first;
                }
            }
        }
        if(qu.empty()){
            qu.push(tmp);
            break;
        }
    }
    // cout<<qu.front()<<'\n';
    int cost2[100001]={0,};
    bool visited2[100001]={0,};
    visited2[qu.front()]=true;
    while(!qu.empty()){
        int x=qu.front();
        qu.pop();
        for(int i=0; i<vec[x].size(); ++i){
            if(visited2[vec[x][i].first]) continue;
            if(cost2[vec[x][i].first]<cost2[x]+vec[x][i].second){
                qu.push(vec[x][i].first);
                cost2[vec[x][i].first]=cost2[x]+vec[x][i].second;
                visited2[vec[x][i].first]=true;
                if(cost2[vec[x][i].first]>diameter) diameter=cost2[vec[x][i].first];
            }
        }
    }
    cout<<diameter<<'\n';
}