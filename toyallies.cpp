#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){//19240
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int tcase=0; tcase<T; ++tcase){
        int N,M;
        cin>>N>>M;
        int visited[N+1]={0,};

        vector<int> vec[N+1];
        int x,y;
        for(int i=0; i<M; ++i){
            cin>>x>>y;
            vec[x].push_back(y);
            vec[y].push_back(x);
        }

        queue<int> qu;
        bool flag=false;
        for(int i=1; i<=N; ++i){
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