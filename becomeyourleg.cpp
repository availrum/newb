#include<iostream>
using namespace std;
int parent[300001], ran[300001], mainbridge=1;
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
    mainbridge=y;
    if(ran[x]==ran[y]) ++ran[y];
}
int main(){//4195
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,tmpa,tmpb;
    cin>>N;
    for(int i=0; i<=N; ++i){
        parent[i]=i;
        ran[i]=1;
    }
    for(int i=0; i<N-2; ++i){
        cin>>tmpa>>tmpb;
        merge_union(tmpa,tmpb);
    }
    int sol=0;
    for(int i=1; i<=N; ++i){
        if(i==mainbridge) continue;
        if(find(i)==i){
            sol=parent[i];
            break;
        }
    }
    cout<<sol<<' '<<mainbridge<<'\n';
}