#include<iostream>
#include<vector>
using namespace std;

struct node{
    int parent;
    int child1;
    int child2;
};
node tree[1000001];

void postorder(int N, node* tree){
    if(tree[N].child1) postorder(tree[N].child1, tree);
    if(tree[N].child2) postorder(tree[N].child2, tree);
    cout<<N<<'\n';
    // cout<<tree[N].child1<<' '<<tree[N].child2<<' '<<tree[N].parent<<'\n';
    // if(tree[N].parent!=N) postorder(tree[N].parent, tree);

    // if(tree[tree[N].parent].child1==N) tree[tree[N].parent].child1=0;
    // else if(tree[tree[N].parent].child2==N) tree[tree[N].parent].child2=0;
}

int main(){//5639
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // node n1;
    // cout<<n1.child1<<' '<<n1.child2<<'\n';
    int N, root=0, bef=0;
    while(cin>>N){
        if(N==0) break;
        if(root==0) root=N;
        
        if(bef==0){
            tree[N].parent=N;
            bef=N;
        }
        else if(bef>N){
            tree[N].parent=bef;
            tree[bef].child1=N;
            bef=N;
        }
        else if(bef<N){
            while((tree[bef].parent != bef) && tree[bef].parent < N){
                bef=tree[bef].parent;
            }
            while(tree[bef].child2<N && tree[bef].child2 != 0){
                bef=tree[bef].child2;
            }
            tree[bef].child2=N;
            tree[N].parent=bef;
            bef=N;
        }
    }
    // cout<<"dd"<<'\n';
    postorder(root,tree);
}