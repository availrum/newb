#include <vector>
#include <iostream>
using namespace std;

vector<int> graph[1001];
bool visited[1001];
int cnt=0;

void dfs(int x){
    visited[x]=true;
    for(int i=0; i<graph[x].size(); i++){
        int y=graph[x][i];
        if(!visited[y]) {
            dfs(y);
            cnt++;
        }
    }
}

int main(){
    int test,c1,c2,k;
    cin>>test>>k;
        for(int j=0; j<k; j++){
            cin>>c1>>c2;
            graph[c1].push_back(c2);
            graph[c2].push_back(c1);
        }
    dfs(1);
    cout<<cnt<<'\n';
}