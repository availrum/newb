#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
int main(){//9719
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int tcase=0; tcase<T; ++tcase){
        int V,E;
        cin>>V>>E;
        int visited[V]={0,};
        vector<int> vec[V];
        int a, b;
        for(int i=0; i<E; ++i){
            cin>>a>>b;
            vec[a].push_back(b);
            vec[b].push_back(a);
        }
        queue<int> qu;
        bool flag=false;
        int cnt=0;
        for(int i=0; i<V; ++i){
            if(visited[i]) continue;
            qu.push(i);
            visited[i]=1;
            ++cnt;
            while(!qu.empty()){
                int x=qu.front();
                // cout<<x<<'\n';
                qu.pop();
                for(int j=0; j<vec[x].size(); ++j){
                    if(!visited[vec[x][j]]){
                        if(visited[x]==2){
                            visited[vec[x][j]]=1;
                        }
                        else if(visited[x]==1){
                            visited[vec[x][j]]=2;
                        }
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
        if(flag){
            cout<<"-1"<<'\n';
            continue;
        }
        int sol=pow(2,cnt);
        cout<<sol<<'\n';
    }
}
