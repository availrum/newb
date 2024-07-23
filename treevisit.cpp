#include<iostream>
using namespace std;
typedef struct node{
    char direc;
    struct node* left;
    struct node* right;
    // node(char d) : direc(d), left(NULL), right(NULL) {}
}node;
void build_node(node* n, char direc, node* left, node* right){
    n->direc = direc;
    n->left = left;
    n->right = right;

}
void preord(node* root){
    cout<<root->direc;
    if(root->left) preord(root->left);
    if(root->right) preord(root->right);
}
void inord(node* root){
    if(root->left) inord(root->left);
    cout<<root->direc;
    if(root->right) inord(root->right);
}
void postord(node* root){
    if(root->left) postord(root->left);
    if(root->right) postord(root->right);
    cout<<root->direc;
}
int main(){//1991
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    node* anode[26];
    for(int i=0; i<26; ++i) anode[i] = new node();
    char c1,c2,c3;
    for(int i=0; i<N; ++i){
        cin>>c1>>c2>>c3;
        if(c2=='.'){
            if(c3=='.') build_node(anode[c1-'A'],c1,NULL,NULL);
            else build_node(anode[c1-'A'],c1,NULL,anode[c3-'A']);
        }
        else{
            if(c3=='.') build_node(anode[c1-'A'],c1,anode[c2-'A'],NULL);
            else build_node(anode[c1-'A'],c1,anode[c2-'A'],anode[c3-'A']);
        }
    }
    preord(anode['A'-'A']);
    cout<<'\n';
    inord(anode['A'-'A']);
    cout<<'\n';
    postord(anode['A'-'A']);
    cout<<'\n';
    for(int i=0; i<N; ++i) delete anode[i];
}