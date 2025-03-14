#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int main(){//11000
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    pair<int,int> ST[N];
    // priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> qu;
    priority_queue<int,vector<int>, greater<int>> qu;
    for(int i=0; i<N; ++i){
        cin>>ST[i].first>>ST[i].second;
    }
    sort(ST,ST+N);
    qu.push(ST[0].second);
    for(int i=1; i<N; ++i){
        // cout<<ST[i].first<<' '<<ST[i].second<<" cur :"<<qu.top()<<" "<<qu.size()<<'\n';
        
        if(ST[i].first < qu.top()){
            qu.push(ST[i].second);
        }
        else{
            qu.pop();
            qu.push(ST[i].second);
        }
    }
    cout<<qu.size()<<'\n';
}