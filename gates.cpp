#include<iostream>
using namespace std;
int gates[100001];
int find(int N){
    if(gates[N]==N) return N;
    if(gates[N]==0) return 0;
    return gates[N]=find(gates[N]);
}
void merge(int a, int b){
    int x=find(a);
    int y=find(b);
    if(x==y) return;
    if(x<y) swap(x,y);
    gates[x]=y;
    
}
int main(){//10775
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int G,P;
    cin>>G>>P;
    for(int i=1; i<=G; ++i){
        gates[i]=i;
    }
    int tmp, cnt=0;
    bool flag=false;
    for(int i=0; i<P; ++i){
        cin>>tmp;
        int x = find(tmp);
        if(x==0) flag=true;
        if(!flag){
            merge(x-1,x);
            ++cnt;
        }
    }
    cout<<cnt<<'\n';
}