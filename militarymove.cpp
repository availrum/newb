#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct pos{
    int posx;
    int posy;
    int wide;
    bool operator< (const pos& other) const{
        return wide<other.wide;
    }
};
int road[10001], height[10001], usize[10001];
int find(int N){
    if(road[N]==N) return N;
    return road[N]=find(road[N]);
}
void merge(int a, int b, int c){
    int x=find(a);
    int y=find(b);
    if(x==y) return;
    if(height[x]>height[y]) swap(x,y);
    road[x]=y;
    if(height[x]==height[y]) ++height[y];
    // cout<<'\n'<<usize[y];
    usize[y]=min(usize[y], c);
    // cout<<'\n'<<usize[y]<<'\n';
}
int main(){//11085
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int p,w;
    cin>>p>>w;
    for(int i=0; i<=p; ++i){
        road[i]=i;
        height[i]=1;
        usize[i]=2147483647;
    }
    int st,ed;
    cin>>st>>ed;
    int a,b,c;
    vector<pos> vec;
    for(int i=0; i<w; ++i){
        cin>>a>>b>>c;
        vec.push_back({a,b,c});
    }
    sort(vec.rbegin(),vec.rend());
    for(int i=0; i<vec.size(); ++i){
        merge(vec[i].posx, vec[i].posy, vec[i].wide);
        if(find(st)==find(ed)) break;
    }
    cout<<usize[find(ed)]<<'\n';
}