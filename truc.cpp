#include<iostream>
#include<queue>
using namespace std;
int main(){ //13335
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,w,L,truc;
    cin>>n>>w>>L;
    // int truc[n];
    queue<int> qu;
    queue<pair<int,int>> bridge;
    for(int i=0; i<n; ++i){
        cin>>truc;//truc[i];
        qu.push(truc);
    }
    int cur_weight=0, cur_time=0;
    while(!qu.empty()){
        int x=qu.front();
        if(!bridge.empty() && cur_time>=bridge.front().second+w){
            cur_weight-=bridge.front().first;
            bridge.pop();
        }

        if(cur_weight+x<=L){
            cur_weight+=x;
            bridge.push({x,cur_time});
            qu.pop();
        }
        ++cur_time;
        // cout<<cur_weight<<' '<<bridge.size()<<' '<<cur_time<<'\n';
    }
    // cout<<'\n';
    while(!bridge.empty()){
        if(cur_time>=bridge.front().second+w) bridge.pop();
        ++cur_time;
    }
    cout<<cur_time<<'\n';
}