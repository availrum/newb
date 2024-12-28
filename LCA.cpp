#include<iostream>
using namespace std;
struct node{
    int parent;
    int height;
};
int check(int N, node* tnode){
    if(tnode[N].parent==N) return tnode[N].height=1;
    else if(tnode[N].height) return tnode[N].height;
    return tnode[N].height=check(tnode[N].parent, tnode)+1;
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
int main(){//3584
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int tcase=0; tcase<T; ++tcase){
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
            tree[B].parent=A;
        }
        for(int i=1; i<=N; ++i){
            check(i, tree);
        }
        // for(int i=1; i<=N; ++i) cout<<i<<' '<<tree[i].height<<'\n';
        // cout<<'\n'<<"123"<<'\n'<<'\n';
        int n1, n2;
        cin>>n1>>n2;
        int sol=find(n1, n2, tree);
        cout<<sol<<'\n';
    }
}