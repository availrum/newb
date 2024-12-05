#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
struct pos{
    int posx;
    int posy;
    int bribes;
    bool operator< (const pos& other) const{
        return bribes<other.bribes;
    }
};
int attendee[10001], height[10001];
long long int money;
int find(int N){
    if(attendee[N]==N) return N;
    return attendee[N]=find(attendee[N]);
}
void merge(int a, int b){
    int x=find(a);
    int y=find(b);
    if(x==y) return;
    if(height[x]>height[y]) swap(x,y);
    attendee[x]=y;
    if(height[x]==height[y]) ++height[y];
}
int main(){//31659
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    for(int i=0; i<=N; ++i){
        attendee[i]=i;
        height[i]=1;
    }
    int a,b,c,node[N+1][N+1];
    for(int i=0; i<=N; ++i){
        for(int j=0; j<=N; ++j){
            node[i][j]=0;
        }
    }
    vector<pos> vec;
    unordered_map<int,int> check;
    for(int i=0; i<M; ++i){
        cin>>a>>b>>c;
        vec.push_back({a,b,c});
        node[a][b]=c;
        check[a]=2;
        check[b]=2;
    }
    sort(vec.rbegin(),vec.rend());
    for(int i=0; i<vec.size(); ++i){
        int x=find(vec[i].posx);
        int y=find(vec[i].posy);
        if(x!=y){
            --check[vec[i].posx];
            --check[vec[i].posy];
            merge(vec[i].posx, vec[i].posy);
            money+=vec[i].bribes;
            if(node[vec[i].posy][vec[i].posx]) money+=node[vec[i].posy][vec[i].posx];
        }
    }
    int edge1=0, edge2=0, cnt=0;
    for(int i=1; i<=N; ++i){
        if(check[i]!=1) continue;
        ++cnt;
        // cout<<check[i]<<" dd "<<i<<'\n';
        if(!edge1){
            edge1=i;
            continue;
        }
        edge2=i;
    }
    if(cnt<3) money+=(node[edge1][edge2] + node[edge2][edge1]);
    cout<<money<<'\n';
}