#include<iostream>
using namespace std;
int node[201], height[201];
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
    int N,M;
    cin>>N>>M;
    for(int i=0; i<=N; ++i){
        node[i]=i;
        height[i]=1;
    }
    int tmp;
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=N; ++j){
            cin>>tmp;
            if(tmp==1){
                merge(i,j);
            }
        }
    }
    bool flag=false;
    int fst;
    for(int i=0; i<M; ++i){
        cin>>tmp;
        if(i==0){
            fst=find(tmp);
        }
        else if(find(tmp)!=fst){
            flag=true;
        }
    }
    if(flag) cout<<"NO"<<'\n';
    else cout<<"YES"<<'\n';
}