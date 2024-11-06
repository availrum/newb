#include<iostream>
using namespace std;
int pnode[100001], height[100001];
int find(int n){
    if(pnode[n]==n) return n;
    return pnode[n]=find(pnode[n]);
}
void merge(int a, int b){
    int x=find(a);
    int y=find(b);
    if(x==y) return;
    if(pnode[x]>pnode[y]) swap(a,b);
    pnode[x]=y;
    if(height[x]==height[y]) ++height[y];
}
int main(){//23324
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    for(int i=0; i<=N; ++i) pnode[i]=i;
    int a,b;
    for(int i=0; i<M; ++i){
        cin>>a>>b;
        merge(a,b);
    }
    int cnt=0;
    for(int i=0; i<N; ++i){
        cin>>b;
        if(i==0){
            a=b;
            continue;
        }

        if(find(a)!=find(b)) ++cnt;
        a=b;
    }
    cout<<cnt<<'\n';
}