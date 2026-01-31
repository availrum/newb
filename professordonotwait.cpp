#include<iostream>
#include<vector>
using namespace std;
pair<int,int> find(vector<pair<int,int>>& arr, int n){
    if(arr[n].first==n) return arr[n];
    int p=arr[n].first;
    pair<int,int> tmp=find(arr,p);
    arr[n].first=tmp.first;
    arr[n].second=arr[n].second+arr[p].second;
    return tmp;
}
void merge(vector<pair<int,int>>& arr, int a, int b, int weight){
    int x=find(arr,a).first;
    int y=find(arr,b).first;
    if(x==y) return;
    if(arr[a].second>weight+arr[b].second){
        arr[y].first=x;
        arr[y].second=arr[a].second-weight-arr[b].second;
    }
    else{
        arr[x].first=y;
        arr[x].second=weight+arr[b].second-arr[a].second;
    }
}
int main(){//3830
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    while(cin>>N>>M){
        if(N==0 && M==0) break;
        vector<pair<int,int>> sample(N+1);
        for(int i=0; i<=N; ++i){
            sample[i]={i,0};
        }
        char sig;
        int a, b, w;
        for(int i=0; i<M; ++i){
            cin>>sig>>a>>b;
            if(sig=='!'){
                cin>>w;
                merge(sample,a,b,w);
            }
            else{
                int x=find(sample,a).first;
                int y=find(sample,b).first;
                if(x!=y){
                    cout<<"UNKNOWN"<<'\n';
                }
                else{
                    // cout<<sample[a].second<<' '<<sample[b].second<<' '
                    cout<<sample[a].second-sample[b].second<<'\n';
                }
            }
        }
        // for(int i=1; i<=N; ++i) cout<<sample[i].second<<' ';
        // cout<<'\n';
    }
}