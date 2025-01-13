#include<iostream>
#include<queue>
using namespace std;
int main(){//14938
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, r;
    cin>>n>>m>>r;
    int item[n+1];
    for(int i=1; i<=n; ++i){
        cin>>item[i];
    }
    int a,b,I;
    int arr[n+1][n+1], dist[n+1][n+1];
    for(int i=0; i<=n; ++i){
        for(int j=0; j<=n; ++j){
            arr[i][j]=0;
            dist[i][j]=2147483647;
        }
    }
    vector<int> vec[n+1];
    for(int i=0; i<r; ++i){
        cin>>a>>b>>I;
        arr[a][b]=I;
        arr[b][a]=I;
    }
    int maxitem=0;
    for(int i=1; i<=n; ++i){
        queue<int> qu;
        qu.push(i);
        dist[i][i]=0;
        while(!qu.empty()){
            int x=qu.front();
            qu.pop();
            for(int j=1; j<=n; ++j){
                if(!arr[x][j]) continue;
                if(dist[i][j]>dist[i][x]+arr[x][j]){
                    qu.push(j);
                    dist[i][j]=dist[i][x]+arr[x][j];

                }
            }
        }
    }
    for(int i=1; i<=n; ++i){
        int tmp=0;
        for(int j=1; j<=n; ++j){
            if(dist[i][j]<100000001 && dist[i][j]<=m){
                // if(i==j) continue;
                tmp+=item[j];
            }
        }
        if(tmp>maxitem) maxitem=tmp;
    }
    cout<<maxitem<<'\n';
}