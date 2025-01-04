#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){//1707
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int K;
    cin>>K;
    for(int tcase=0; tcase<K; ++tcase){
        int V,E;
        cin>>V>>E;
        int visited[V+1]={0,};

        vector<int> vec[V+1];
        int u,v;
        for(int i=0; i<E; ++i){
            cin>>u>>v;
            vec[u].push_back(v);
            vec[v].push_back(u);
        }

        queue<int> qu;
        bool flag=false;
        for(int i=1; i<=V; ++i){
            if(visited[i]) continue;

            qu.push(i);
            visited[i]=1;
            while(!qu.empty()){
                int x=qu.front();
                qu.pop();
                for(int j=0; j<vec[x].size(); ++j){
                    if(!visited[vec[x][j]]){
                        if(visited[x]==2) visited[vec[x][j]]=1;
                        else visited[vec[x][j]]=2;
                        qu.push(vec[x][j]);
                    }
                    else if(visited[x]==visited[vec[x][j]]){
                        flag=true;
                        break;
                    }
                }
                if(flag) break;
            }
        }
        if(flag==false) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
}