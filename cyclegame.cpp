#include<iostream>
using namespace std;
int node[500002], height[500002];
int find(int n){
    if(n==node[n]) return n;
    return node[n]=find(node[n]);
}
void merge(int a, int b){
    int x=find(a);
    int y=find(b);
    if(x==y) return;
    if(height[x]> height[y]) swap(x,y);
    node[x]=y;
    if(height[x]==height[y]) ++height[y];
    
}
int main(){//20040
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,log=0;
    cin>>n>>m;
    for(int i=0; i<=n+1; ++i){
        node[i]=i;
        height[i]=1;
    }
    int tmpa, tmpb;
    for(int i=1; i<=m; ++i){
        cin>>tmpa>>tmpb;
        if(find(tmpa)==find(tmpb)){
            if(log==0 || log>i) log=i;
        }
        merge(tmpa,tmpb);
    }
    cout<<log<<'\n';
}