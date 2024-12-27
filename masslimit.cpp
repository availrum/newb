#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct bridge{
    int br1;
    int br2;
    int cost;
    bool operator < (const bridge& other) const{
        return cost>other.cost;
    }
};
int maxcost=2147483647;
int find(int N, int* node){
    if(node[N]==N) return N;
    return node[N]=find(node[N], node);
}
void merge(int a, int b, int* node, int weight){
    int x = find(a, node);
    int y = find(b, node);
    if(x==y) return;
    if(x>y) swap(x,y);
    node[x]=y;
    maxcost=min(maxcost,weight);
}
int main(){//1939
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    int node[N+1];
    for(int i=0; i<=N; ++i) node[i]=i;
    
    vector<bridge> vec;
    bridge tmp;
    for(int i=0; i<M; ++i){
        cin>>tmp.br1>>tmp.br2>>tmp.cost;
        vec.push_back(tmp);
    }
    int st,ed;
    cin>>st>>ed;
    sort(vec.begin(), vec.end());
    for(int i=0; i<vec.size(); ++i){
        merge(vec[i].br1, vec[i].br2, node, vec[i].cost);
        if(find(st, node)==find(ed, node)) break;
        // cout<<vec[i].br1<<' '<<vec[i].br2<<' '<<vec[i].cost<<'\n';
    }
    cout<<maxcost<<'\n';
}