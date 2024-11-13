#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
using namespace std;
int main(){//2623
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    vector<int> vec[N+1];
    unordered_map<int,int> check;
    for(int i=0; i<M; ++i){
        int iter;
        cin>>iter;
        int a,b;
        for(int j=0; j<iter; ++j){
            cin>>b;
            if(j==0) a=b;
            if(a!=b){
                vec[a].push_back(b);
                ++check[b];
            }
            a=b;
        }
    }
    queue<int> qu,sol;
    for(int i=1; i<=N; ++i){
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
            --check[vec[x][i]];
        }
        sol.push(x);
    }
    for(int i=1; i<=N; ++i){
        if(check[i]){
            cout<<"0"<<'\n';
            return 0;
        }
    }
    while(!sol.empty()){
        int x=sol.front();
        sol.pop();
        cout<<x<<'\n';
    }
}
