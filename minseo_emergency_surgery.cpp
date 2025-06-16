#include<iostream>
using namespace std;
int find(int n, int* arr){
    if(arr[n]==n) return n;
    return arr[n]=find(arr[n],arr);
}
void merge(int a, int b, int* arr){
    int x=find(a,arr);
    int y=find(b,arr);
    if(x==y) return;
    if(x>y) swap(x,y);
    arr[x]=y;
}
int main(){//20955
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    int neuron[N+1];
    for(int i=0; i<=N; ++i){
        neuron[i]=i;
    }
    int u,v, cnt=0;
    for(int i=0; i<M; ++i){
        cin>>u>>v;
        if(find(u,neuron)==find(v,neuron)){
            ++cnt;
        }
        merge(u,v,neuron);
    }
    bool check[N+1]={false};
    check[find(1,neuron)]=true;
    for(int i=2; i<=N; ++i){
        int x=find(i,neuron);
        if(!check[x]){
            ++cnt;
            check[x]=true;
        }
    }
    cout<<cnt<<'\n';
}