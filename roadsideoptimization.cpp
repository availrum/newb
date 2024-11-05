#include<iostream>
#include<unordered_map>
using namespace std;
int find(int n, int* node){
    if(n==node[n]) return n;
    return node[n]=find(node[n],node);
}
void merge(int a, int b, int* node, int* height){
    int x=find(a,node);
    int y=find(b,node);
    if(x==y) return;
    if(height[x]>height[y]) swap(x,y);
    node[x]=y;
    if(height[x]==height[y]) ++height[y];
}
int main(){//20757
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int Test,t;
    cin>>Test;
    for(int i=0; i<Test; ++i){
        cin>>t;
        int road[t+1], height[t+1];
        for(int j=1; j<=t; ++j){
            road[j]=j;
            height[j]=1;
        }
        int tmp,arr[t+1][t+1];
        for(int j=1; j<=t; ++j){ 
            for(int k=1; k<=t; ++k){
                cin>>tmp;
                arr[j][k]=tmp;
                if(tmp==0) continue;
                if(j==k) continue;
                merge(j,k,road,height);
            }
        }
        int cnt=0;
        unordered_map<int,int> ma;
        for(int j=1; j<=t; ++j){
            if(ma[find(j,road)]==0) ma[find(j,road)]=1;
            else ++cnt;
        }
        cout<<cnt<<'\n';
    }
}