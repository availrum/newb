#include<iostream>
#include<queue>
#include<deque>
using namespace std;
int main(){ //11003
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,L,t;
    cin>>N>>L;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> qu;
    for(int i=0; i<N; ++i){
        cin>>t;
        if(qu.empty() || qu.top().first<t) qu.push({t,i});
        else{
            while(!qu.empty()){
                qu.pop();
            }
            qu.push({t,i});
        }
        //i+1-L
        while(!qu.empty() && qu.top().second+L<=i){
            qu.pop();
        }
        if(i!=N-1) cout<<qu.top().first<<' ';
        else cout<<qu.top().first<<'\n';
    }
}