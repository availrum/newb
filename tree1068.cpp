#include<iostream>
#include<vector>
using namespace std;
int broken=-1, sol;
void dfs(int N, vector<vector<int>> tree){
    if(N==broken) return;
    if(tree[N].size()==0 || (tree[N].size()==1 && tree[N][0]==broken)){
        // cout<<N<<'\n';
        ++sol;
        return;
    }
    for(int i=0; i<tree[N].size(); ++i){
        if(tree[N][i]==broken) continue;
        dfs(tree[N][i], tree);
    }
    return;
}
int main(){//1068
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    vector<vector<int>> tree(N);
    bool visited[N]={false,};
    int parent, start;
    for(int i=0; i<N; ++i){
        cin>>parent;
        if(parent==-1){
            start=i;
        }
        else tree[parent].push_back(i);
    }
    cin>>broken;
    dfs(start,tree);
    cout<<sol<<'\n';
}