#include<iostream>
#include<unordered_map>
using namespace std;
int find(int N, int* node){
    if(node[N]==N) return N;
    return node[N]=find(node[N],node);
}
void merge(int a, int b, int* node){
    int x=find(a,node);
    int y=find(b,node);
    if(x==y) return;
    if(x<y) swap(x,y);
    node[x]=y;
}
int main(){//4803
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    int tcase=1;
    while(cin>>N>>M){
        if(N==0 && M==0) break;
        int node[N+1];
        for(int i=0; i<=N; ++i){
            node[i]=i;
        }
        int a,b;
        for(int i=0; i<M; ++i){
            cin>>a>>b;
            int x=find(a, node);
            int y=find(b, node);
            if(x==y){
                merge(0,x,node);
            }
            else merge(x, y, node);
        }
        int cnt=0;
        unordered_map<int,int> check;
        for(int i=1; i<=N; ++i){
            int x=find(i,node);
            if(x==0) continue;
            if(!check[x]){
                ++cnt;
                // cout<<x<<' '<<check[x]<<'\n';
                check[x]=1;
            }
        }
        cout<<"Case "<<tcase<<": ";
        if(cnt==0) cout<<"No trees."<<'\n';
        else if(cnt==1) cout<<"There is one tree."<<'\n';
        else cout<<"A forest of "<<cnt<<" trees."<<'\n';
        ++tcase;
    }
}