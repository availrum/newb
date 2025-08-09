#include<iostream>
using namespace std;
int find(int n, pair<int,int>* arr){
    if(arr[n].first==n) return n;
    return arr[n].first=find(arr[n].first, arr);
}
void merge(int a, int b, pair<int,int>* arr){
    int x=find(a,arr);
    int y=find(b,arr);
    if(x==y) return;
    if(x<y) swap(x,y);
    arr[x].first=y;
    arr[y].second+=arr[x].second;
}
int main(){ //17250
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    pair<int,int> galaxy[N+1];
    for(int i=1; i<=N; ++i){
        galaxy[i].first=i;
        cin>>galaxy[i].second;
    }
    for(int i=0; i<M; ++i){
        int g1, g2;
        cin>>g1>>g2;
        merge(g1,g2, galaxy);
        cout<<galaxy[find(g1,galaxy)].second<<'\n';
    }
}