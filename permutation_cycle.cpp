#include<iostream>
#include<queue>
using namespace std;
int main(){ //10451
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int i=0; i<T; ++i){
        int N;
        cin>>N;
        int permutation[N+1];
        for(int i=0; i<N; ++i){
            cin>>permutation[i+1];
        }
        bool visited[N+1]={false,};
        queue<int> qu;
        int cnt=0;
        for(int i=1; i<=N; ++i){
            if(visited[i]) continue;
            qu.push(i);
            ++cnt;
            while(!qu.empty()){
                int x=qu.front();
                qu.pop();
                if(!visited[permutation[x]]){
                    visited[permutation[x]]=true;
                    qu.push(permutation[x]);
                }
            }
        }
        cout<<cnt<<'\n';
    }
} 