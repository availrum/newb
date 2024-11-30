#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
int main(){//1516
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,tmp;
    cin>>N;
    int time[N+1];
    vector<int> vec[N+1];
    unordered_map<int,int> check, mintime;
    for(int i=1; i<=N; ++i){
        cin>>time[i];
        while(true){
            cin>>tmp;
            if(tmp==-1) break;
            vec[tmp].push_back(i);
            ++check[i];
        }
    }
    queue<int> qu;
    for(int i=1; i<=N; ++i){
        if(!check[i]) qu.push(i);
        mintime[i]=time[i];
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
    }
    for(int i=1; i<=N; ++i){
        cout<<mintime[i];
        
        cout<<'\n';
    }
}