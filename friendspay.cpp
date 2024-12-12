#include<iostream>
#include<algorithm>
using namespace std;
int node[10001], pay[10001];
int mincost;
struct person{
    int num;
    int cost;
    bool operator< (const person& other) const{
        return cost<other.cost;
    }
};
int find(int n){
    if(n==node[n]) return n;
    return node[n]=find(node[n]);
    //경로압축
}
void merge(int a, int b, int money){
    int x=find(a);
    int y=find(b);
    if(x==y) return;
    if(x<y) swap(x,y);
    node[x]=y;
    mincost+=money;
}
int main(){//16562
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M,k;
    cin>>N>>M>>k;
    person frd[N+1];
    int tmp;
    frd[0].num=0;
    frd[0].cost=0;
    for(int i=1; i<=N; ++i){
        node[i]=i;
        cin>>tmp;
        frd[i].num=i;
        frd[i].cost=tmp;
    }
    sort(frd,frd+N+1);
    int a,b;
    for(int i=0; i<M; ++i){
        cin>>a>>b;
        merge(a,b,0);
    }
    for(int i=0; i<=N; ++i){
        merge(0,frd[i].num,frd[i].cost);
    }
    if(mincost>k) cout<<"Oh no"<<'\n';
    else cout<<mincost<<'\n';
}