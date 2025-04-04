#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){//1240
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    vector<pair<int,int>> arr[N+1];
    int a,b,dist;
    for(int i=0; i<N-1; ++i){
        cin>>a>>b;
        cin>>dist;
        arr[a].push_back({b,dist});
        arr[b].push_back({a,dist});
    }
    for(int i=0; i<M; ++i){
        cin>>a>>b;
        bool flag=false;
        int visited[N+1]={0,};
        // visited[a]=true;
        queue<int> qu;
        qu.push(a);
        while(!qu.empty()){
            int x=qu.front();
            qu.pop();
            for(int j=0; j<arr[x].size(); ++j){
                if(visited[arr[x][j].first]) continue;
                qu.push(arr[x][j].first);
                visited[arr[x][j].first]=visited[x]+arr[x][j].second;
                if(arr[x][j].first==b){
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }
        cout<<visited[b]<<'\n';
    }
}