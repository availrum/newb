#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int node[200001];
int height[200001];
int find(int n){
    if(n==node[n]) return n;
    return node[n]=find(node[n]);
    //경로압축
}
void merge(int a, int b){
    int x=find(a);
    int y=find(b);
    if(x==y){
        cout<<height[x]<<'\n';
        return;
    }
    // cout<<x<<""<<y<<'\n';
    if(height[x]>height[y]) swap(x,y);
    node[x]=y;
    height[y]+=height[x];
    cout<<height[y]<<'\n';
}
int main(){//4195
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T,F;
    cin>>T;
    for(int tkase=0; tkase<T; ++tkase){
        cin>>F;
        unordered_map<string, int> numbering;
        int num=0;
        string st1, st2;
        for(int i=0; i<F; ++i){
            cin>>st1>>st2;
            if(!numbering.count(st1)){
                ++num;
                node[num]=num;
                height[num]=1;
                numbering[st1]=num;
            }
            if(!numbering.count(st2)){
                ++num;
                node[num]=num;
                height[num]=1;
                numbering[st2]=num;
            }
            merge(numbering[st1],numbering[st2]);
        }
    }
}