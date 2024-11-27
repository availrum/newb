#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
int main(){//2056
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int time[N+1]={0,},work;
    vector<int> vec[N+1];
    unordered_map<int,int> check;
    for(int i=1; i<=N; ++i){
        cin>>time[i]>>work;
        for(int j=0; j<work; ++j){
            int tmp;
            cin>>tmp;
            vec[tmp].push_back(i);
            ++check[i];
        }
    }
    queue<int> qu;
    int mintime[N+1];
    for(int i=1; i<=N; ++i){
        if(!check[i]) qu.push(i);
        mintime[i]=time[i];
    }
    int sol;
    while(!qu.empty()){
        int x=qu.front();
        int y=qu.front();
        qu.pop();
        for(int i=0; i<vec[x].size(); ++i){
            if(check[vec[x][i]]==1){
                qu.push(vec[x][i]);
            }
            --check[vec[x][i]];
            mintime[vec[x][i]]=max(mintime[vec[x][i]],mintime[x]+time[vec[x][i]]);
        }
    }
    for(int i=1; i<=N; ++i) sol=max(sol,mintime[i]);
    cout<<sol<<'\n';
}