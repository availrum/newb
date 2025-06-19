#include<iostream>
#include<queue>
using namespace std;
int main(){ //2075
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    priority_queue<int,vector<int>,greater<int>> qu;
    int tmp;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin>>tmp;
            qu.push(tmp);
            if(qu.size()>N){
                qu.pop();
            }
        }
    }
    // while(!qu.empty()){
    //     cout<<qu.top()<<'\n';
    //     qu.pop();
    // }
    cout<<qu.top()<<'\n';
} 