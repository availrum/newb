#include<iostream>
using namespace std;
int parent[1000001];
int ran[1000001];
int find(int num){
    if(num==parent[num]) return num;
    return parent[num]=find(parent[num]);
}
void merge_union(int a, int b){
    int x=find(a);
    int y=find(b);
    if(x==y) return;
    if(ran[x]>ran[y]) swap(x,y);
    parent[x]=y;
    if(ran[x]==ran[y]) ++ran[y];
}
int main(){//1717
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin>>n>>m;
    for(int i=0; i<=n; ++i){
        parent[i]=i;
        ran[i]=1;
    }
    int oper, a, b;
    for(int i=0; i<m; ++i){
        cin>>oper>>a>>b;
        if(oper==0){
            merge_union(a,b);
        }
        else if(oper==1){
            int x = find(a);
            int y = find(b);
            if(x==y) cout<<"YES"<<'\n';
            else cout<<"NO"<<'\n';
        }
    }
}