#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct connect{
    int com1;
    int com2;
    int cost;
    bool operator< (const connect& other) const{
        return cost<other.cost;
    }
};
int find(int n, int* arr){
    if(arr[n]==n) return n;
    return arr[n]=find(arr[n], arr);
}
void merge(int a, int b, int* arr){
    int x=find(a,arr);
    int y=find(b,arr);
    if(x==y) return;
    if(x>y) swap(x,y);
    arr[x]=y;
}
int main(){ //1922
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    vector<connect> vec;
    for(int i=0; i<M; ++i){
        connect input;
        cin>>input.com1>>input.com2>>input.cost;
        vec.push_back(input);
    }
    sort(vec.begin(), vec.end());
    int link[N+1];
    for(int i=0; i<=N; ++i){
        link[i]=i;
    }
    int total_cost=0;
    for(int i=0; i<vec.size(); ++i){
        if(find(vec[i].com1,link)==find(vec[i].com2,link)) continue;
        merge(vec[i].com1,vec[i].com2, link);
        total_cost+=vec[i].cost;
    }
    cout<<total_cost<<'\n';
}