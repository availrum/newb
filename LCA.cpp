#include<iostream>
#include<vector>
using namespace std;
struct node{
    int parent;
    int height;
};
vector<int> vec[50001];
void dfs(int N, node* tnode, int cnt){
    tnode[N].height=cnt;
    for(int i=0; i<vec[N].size(); ++i){
        if(!tnode[vec[N][i]].height){
            tnode[vec[N][i]].parent=N;
            dfs(vec[N][i], tnode, cnt+1);
        }
    }
}
int find(int a, int b, node* tnode){
    // cout<<'\n';
    while(a != b){
        // cout<<'\n';
        if(tnode[a].height < tnode[b].height) swap(a,b);

        if(tnode[a].parent == tnode[b].parent) return tnode[a].parent;

        if(tnode[a].height!=tnode[b].height){
            a=tnode[a].parent;
            continue;
        }
        else if(tnode[a].height==tnode[b].height){
            a=tnode[a].parent;
            b=tnode[b].parent;
        }
    }
    return a;
}
int main(){//11437
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    node tree[N+1];
    for(int i=0; i<=N; ++i){
        tree[i].parent=i;
        tree[i].height=0;
    }
    int A,B;
    for(int i=0; i<N-1; ++i){
        cin>>A>>B;
        vec[A].push_back(B);
        vec[B].push_back(A);
    }
    dfs(1, tree, 1);
    // cout<<'\n'<<"123"<<'\n'<<'\n';
    int M;
    cin>>M;
    for(int i=0; i<M; ++i){
        int n1, n2;
        cin>>n1>>n2;
        int sol=find(n1, n2, tree);
        cout<<sol<<'\n';
    }
}