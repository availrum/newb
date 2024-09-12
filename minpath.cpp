#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){//1753
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int V,E;
    cin>>V>>E;
    int node1;
    cin>>node1;
    vector<vector<pair<int,int>>> arr(V+1);
    long long int cost[V+1];
    for(int i=0; i<=V; ++i){
        cost[i]=2147483646;
    }
    int st,ed,val;
    for(int i=0; i<E; ++i){
        cin>>st>>ed>>val;
        arr[st].push_back({val,ed});
    }
    cost[node1]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pqu;
    pqu.push({0,node1});
    while(!pqu.empty()){
        int quval=pqu.top().first;
        int qucur=pqu.top().second;
        pqu.pop();
        if(cost[qucur]!=quval) continue;
        for(auto i : arr[qucur]){
            if(quval+i.first<cost[i.second]){
                cost[i.second]=quval+i.first;
                pqu.push({cost[i.second],i.second});
            }
        }
        // for(int i=0; i<arr[qucur].size(); ++i){
        //     if(quval+arr[qucur][i].first<cost[arr[qucur][i].second]){
        //         cost[arr[qucur][i].second]=quval+arr[qucur][i].first;
        //         pqu.push({cost[arr[qucur][i].second],arr[qucur][i].second});
        //     }
        // }
    }
    for(int i=1; i<=V; ++i){
        if(node1==i) cout<<"0"<<'\n';
        else if(cost[i]>1000000) cout<<"INF"<<'\n';
        else cout<<cost[i]<<'\n';
    }
}