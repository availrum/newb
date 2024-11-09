#include<iostream>
using namespace std;
int pnode[100001], height[100001];
int find(int n){
    if(pnode[n]==n) return n;
    return pnode[n]=find(pnode[n]);
}
void merge(int a, int b){
    int x=find(a);
    int y=find(b);
    if(x==y) return;
    if(height[x]>height[y]) swap(x,y);
    pnode[x]=y;
    height[y]+=height[x];
}
int main(){//23324
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M,K;
    cin>>N>>M>>K;
    for(int i=1; i<=N; ++i){
        pnode[i]=i;
        height[i]=1;
    }
    int a,b,tmp1,tmp2;
    for(int i=1; i<=M; ++i){
        cin>>a>>b;
        if(i==K){
            tmp1=a;
            tmp2=b;
            continue;
        }
        merge(a,b);
    }
    int x=find(tmp1);
    int y=find(tmp2);
    if(x==y){
        cout<<"0"<<'\n';
    }
    else{
        long long sol=static_cast<long long>(height[x])*static_cast<long long>(height[y]);
        //타입캐스트없을시 16퍼 있으면99
        cout<<sol<<'\n';
    }
}