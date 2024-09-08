#include<iostream>
#include<queue>
using namespace std;
int main(){//1916
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    int arr[N+1][N+1];
    long long int cost[N+1];
    for(int i=0; i<=N; ++i){
        cost[i]=2147483646;
        for(int j=0; j<=N; ++j) arr[i][j]=-1;
    }
    int st,ed,val;
    for(int i=0; i<M; ++i){
        cin>>st>>ed>>val;
        if(arr[st][ed]==-1 || arr[st][ed]>val) arr[st][ed]=val;
    }
    queue<int> qu;
    cin>>st>>ed;
    qu.push(st);
    cost[st]=0;
    while(!qu.empty()){
        int x=qu.front();
        qu.pop();
        if(x==ed) continue;
        for(int i=1; i<=N; ++i){
            if(arr[x][i]==-1) continue;
            if(cost[i]>cost[x]+arr[x][i]){
                cost[i]=cost[x]+arr[x][i];
                qu.push(i);
            }
        }
    }
    cout<<cost[ed]<<'\n';
}