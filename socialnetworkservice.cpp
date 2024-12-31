#include<iostream>
#include<vector>
using namespace std;
struct node{
    int parent;
    int height;
};
vector<int> vec[1000001];
int sol;
int dfs(int N, node* tnode, int cnt){
    tnode[N].height=cnt;
    int flag=0, tmp, itercnt=0;
    for(int i=0; i<vec[N].size(); ++i){
        if(!tnode[vec[N][i]].height){
            tnode[vec[N][i]].parent=N;
            tmp=dfs(vec[N][i], tnode, cnt+1);
            
            if(tmp==0) flag=1;
            ++itercnt;
        }
    }
    if(!itercnt) flag=0;
    if(flag) ++sol; 
    return flag;
}
int main(){//2533
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
    cout<<sol<<'\n';
    
}