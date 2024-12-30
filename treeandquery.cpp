#include<iostream>
#include<vector>
using namespace std;
struct node{
    int parent;
    int height;
};
vector<int> vec[100001];
long long int sol[100001];
int dfs(int N, node* tnode, int cnt){
    long long int numofnode=1;
    tnode[N].height=cnt;
    for(int i=0; i<vec[N].size(); ++i){
        if(!tnode[vec[N][i]].height){
            tnode[vec[N][i]].parent=N;
            numofnode+=dfs(vec[N][i], tnode, cnt+1);
        }
    }
    sol[N]=numofnode;
    return numofnode;
}
int main(){//15681
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, R, Q;
    cin>>N>>R>>Q;
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
    dfs(R, tree, 1);
    for(int i=0; i<Q; ++i){
        int num;
        cin>>num;
        cout<<sol[num]<<'\n';
    }
}