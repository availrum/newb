#include<iostream>
#include<queue>
using namespace std;
struct tree{
    int parent;
    int height;
};
int dfs(tree* node, int N){
    if(node[N].height==0) return 0;
    else if(node[node[N].parent].height<21) return node[N].height=node[node[N].parent].height+1;
    return node[N].height = dfs(node, node[node[N].parent].height)+1;
}
int main(){//13237
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    tree node[N];
    for(int i=1; i<=N; ++i){
        cin>>node[i].parent;
        if(node[i].parent == -1) node[i].height=0;
        else node[i].height=21;
    }
    for(int i=1; i<=N; ++i){
        dfs(node, i);
        cout<<node[i].height<<'\n';
    }
}