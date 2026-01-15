#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int find(vector<int>& frd, int n){
    if(frd[n]==n) return n;
    return frd[n]=find(frd, frd[n]);
}
void merge(int a, int b, vector<int>& group){
    int x=find(group,a);
    int y=find(group,b);
    if(x==y) return;
    if(x<y) swap(x,y);
    group[x]=y;
}
int main(){ //1765
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int> group(n+1);
    vector<vector<int>> enermy(n+1);
    for(int i=0; i<=n; ++i) group[i]=i;
    for(int i=0; i<m; ++i){
        char c;
        int p,q;
        cin>>c>>p>>q;
        if(c=='F') merge(p,q,group);
        else{
            enermy[p].push_back(q);
            enermy[q].push_back(p);
        }
    }
    for(int i=1; i<=n; ++i){
        queue<pair<int,int>> qu;
        vector<bool> visited(n+1,false);
        qu.push({i,0});
        while(!qu.empty()){
            int x=qu.front().first;
            int y=qu.front().second;
            qu.pop();
            for(int j=0; j<enermy[x].size(); ++j){
                if(visited[enermy[x][j]]) continue;
                if(y==1){
                    merge(i,enermy[x][j],group);
                }
                visited[enermy[x][j]]=true;
                qu.push({enermy[x][j],1-y});
            }
        }
    }
    vector<bool> used(n+1,false);
    int cnt=0;
    for(int i=1; i<=n; ++i){
        if(used[find(group,i)]) continue;
        used[find(group,i)]=true;
        ++cnt;
    }
    cout<<cnt<<'\n';
}