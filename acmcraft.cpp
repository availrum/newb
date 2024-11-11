#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
using namespace std;
int main(){//1005
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int iter=0; iter<T; ++iter){
        int N,K;
        cin>>N>>K;
        int time[N+1];
        for(int i=1; i<=N; ++i){
            cin>>time[i];
        }
        int a,b;
        vector<int> vec[N+1];
        unordered_map<int,int> check;
        for(int i=0; i<K; ++i){
            cin>>a>>b;
            vec[a].push_back(b);
            ++check[b];
        }
        queue<int> qu;
        int mintime[N+1];
        for(int i=1; i<=N; ++i){
            mintime[i]=time[i];
            if(!check[i]){
                qu.push(i);
            }
        }
        while(!qu.empty()){
            int x=qu.front();
            qu.pop();
            for(int i=0; i<vec[x].size(); ++i){
                if(check[vec[x][i]]==1){
                    qu.push(vec[x][i]);
                }
                if(mintime[vec[x][i]]<mintime[x]+time[vec[x][i]]){
                    mintime[vec[x][i]]=mintime[x]+time[vec[x][i]];
                }
                --check[vec[x][i]];
            }
            // cout<<x;
            // if(!qu.empty()) cout<<' ';
            // else cout<<'\n';
        }
        int W;
        cin>>W;
        cout<<mintime[W]<<'\n';
    }
}