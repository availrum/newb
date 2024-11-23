#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int node[30001];
int peoplenum[30001];
int candi[30001];
int find(int n){
    if(n==node[n]) return n;
    return node[n]=find(node[n]);
    //경로압축
}
void merge(int a, int b){
    int x=find(a);
    int y=find(b);
    if(x==y){
        return;
    }
    if(candi[x]>candi[y]) swap(x,y);
    node[x]=y;
    peoplenum[y]+=peoplenum[x];
    candi[y]+=candi[x];
}
int main(){//20303
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M,K;
    cin>>N>>M>>K;
    for(int i=1; i<=N; ++i){
        cin>>candi[i];
        node[i]=i;
        peoplenum[i]=1;
    }
    int a,b;
    for(int i=0; i<M; ++i){
        cin>>a>>b;
        merge(a,b);
    }
    vector<int> Weight, Value;
    unordered_map<int,int> check;
    Weight.push_back(0);
    Value.push_back(0);
    for(int i=1; i<=N; ++i){
        int x=find(i);
        if(!check[x]){
            Weight.push_back(peoplenum[x]);
            Value.push_back(candi[x]);
            ++check[x];
        }
    }
    // for(int i=1; i<=N; ++i) cout<<candi[find(i)]<<' ';
    // cout<<'\n';
    int tot[Value.size()][K];
    for(int i=0; i<Value.size(); ++i){
        for(int j=0; j<K; ++j){
            tot[i][j]=0;
        }
    }
    for(int i=1; i<Value.size(); ++i){
        for(int j=0; j<K; ++j){
            if(j>=Weight[i]) tot[i][j]=max(tot[i-1][j], tot[i-1][j-Weight[i]]+Value[i]);
            else tot[i][j]=tot[i-1][j];
        }
    }
    cout<<tot[Value.size()-1][K-1]<<'\n';
}