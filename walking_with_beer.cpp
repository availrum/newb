#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){ //9205
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    for(int tcase=0; tcase<t; ++tcase){
        int N;
        cin>>N;
        vector<pair<int,int>> convi(N+2);
        for(int i=0; i<N+2; ++i){
            cin>>convi[i].first>>convi[i].second;
        }
        bool visited[N+2]={false,};
        queue<int> qu;
        qu.push(0);
        visited[0]=true;
        while(!qu.empty()){
            int x=qu.front();
            qu.pop();
            for(int i=1; i<N+2; ++i){
                if(visited[i]) continue;
                int cur_dist=abs(convi[x].first-convi[i].first)+abs(convi[x].second-convi[i].second);
                if(cur_dist>1000) continue;
                visited[i]=true;
                qu.push(i);
                if(visited[N+1]) break;
            }
            if(visited[N+1]) break;
        }
        if(visited[N+1]) cout<<"happy\n";
        else cout<<"sad\n";
    }
} 