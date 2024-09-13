#include<iostream>
#include<queue>
using namespace std;
int main(){//11404
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    int cost[n+1][n+1],arr[n+1][n+1];
    for(int i=0; i<=n; ++i) for(int j=0; j<=n; ++j){
        arr[i][j]=0;
        cost[i][j]=2147483646;
    }
    for(int i=0; i<m; ++i){
        int st,ed,val;
        cin>>st>>ed>>val;
        if(arr[st][ed]==0 || arr[st][ed]>val) arr[st][ed]=val;
    }
    for(int i=1; i<=n; ++i){
        queue<int> qu;
        qu.push(i);
        cost[i][i]=0;
        while(!qu.empty()){
            int x=qu.front();
            qu.pop();
            for(int j=1; j<=n; ++j){
                if(j==x) continue;
                if(arr[x][j]!=0 && (cost[i][j]>cost[i][x]+arr[x][j])){
                    cost[i][j]=cost[i][x]+arr[x][j];
                    qu.push(j);
                }
            }
        }
    }
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            if(cost[i][j]==2147483646) cout<<"0";
            else cout<<cost[i][j];
            if(j!=n) cout<<' ';
            else cout<<'\n';
        }
    }
}