#include<iostream>
#include<vector>
using namespace std;
bool flag=false;
void btr(vector<vector<int>>& frd, vector<bool> visited, int cur, int num){
    if(flag) return;
    if(num>=5){
        flag=true;
        return;
    }
    for(int i=0; i<frd[cur].size(); ++i){
        if(visited[frd[cur][i]]) continue;
        visited[frd[cur][i]]=true;
        btr(frd,visited,frd[cur][i],num+1);
        visited[frd[cur][i]]=false;
    }
}
int main(){ //13023
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    vector<vector<int>> frd(N);
    int a,b;
    for(int i=0; i<M; ++i){
        cin>>a>>b;
        frd[a].push_back(b);
        frd[b].push_back(a);
    }
    vector<bool> visited(N,false);
    for(int i=0; i<N; ++i){
        visited[i]=true;
        btr(frd,visited,i,1);
        visited[i]=false;
    }
    if(flag) cout<<"1\n";
    else cout<<"0\n";
} 