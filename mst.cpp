#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int node[10001], height[10001];
int weight;
struct pos{
    int x;
    int y;
    int val;
};
bool bet(pos a, pos b){
    if(a.val<b.val) return true;
    else return false; 
}
int find(int n){
    if(n==node[n]) return n;
    return node[n]=find(node[n]);
    //경로압축
}
void merge(int a, int b, int c){
    int x=find(a);
    int y=find(b);
    if(x==y) return;
    if(x>y) swap(x,y);
    node[x]=y;
    weight+=c;
    if(height[x]==height[y]) ++height[y];
}
int main(){//1197
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int V,E;
    cin>>V>>E;
    for(int i=1; i<=V; ++i) node[i]=i;
    vector<pos> edge;
    int A,B,C;
    for(int i=0; i<E; ++i){
        cin>>A>>B>>C;
        edge.push_back({A,B,C});
    }
    sort(edge.begin(), edge.end(), bet);
    for(int i=0; i<edge.size(); ++i){
        merge(edge[i].x,edge[i].y,edge[i].val);
    }
    cout<<weight<<'\n';
}