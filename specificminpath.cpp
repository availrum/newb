#include<iostream>
#include<queue>
#include<deque>
using namespace std;
int main(){//1916
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,E;
    cin>>N>>E;
    int arr[N+1][N+1];
    long long int cost1[N+1],costv1[N+1],costv2[N+1];
    for(int i=0; i<=N; ++i){
        cost1[i]=2147483646;
        costv1[i]=2147483646;
        costv2[i]=2147483646;
        for(int j=0; j<=N; ++j) arr[i][j]=-1;
    }
    int st,ed,val;
    for(int i=0; i<E; ++i){
        cin>>st>>ed>>val;
        arr[st][ed]=val;
        arr[ed][st]=val;
    }
    queue<int> qu;
    int node1,node2;
    cin>>node1>>node2;
    // for(int i=0; i<=N; ++i) num[i]=0;
    qu.push(1);
    cost1[1]=0;
    while(!qu.empty()){
        int x=qu.front();
        qu.pop();
        for(int i=1; i<=N; ++i){
            if(arr[x][i]==-1) continue;
            if(cost1[i]>cost1[x]+arr[x][i]){
                cost1[i]=cost1[x]+arr[x][i];
                qu.push(i);
            }
        }
    }
    //1에서부터의 거리 계산

    qu.push(node1);
    costv1[node1]=0;
    while(!qu.empty()){
        int x=qu.front();
        qu.pop();
        for(int i=1; i<=N; ++i){
            if(arr[x][i]==-1) continue;
            if(costv1[i]>costv1[x]+arr[x][i]){
                costv1[i]=costv1[x]+arr[x][i];
                qu.push(i);
            }
        }
    }
    //node1에서의 거리 계산

    qu.push(node2);
    costv2[node2]=0;
    while(!qu.empty()){
        int x=qu.front();
        qu.pop();
        for(int i=1; i<=N; ++i){
            if(arr[x][i]==-1) continue;
            if(costv2[i]>costv2[x]+arr[x][i]){
                costv2[i]=costv2[x]+arr[x][i];
                qu.push(i);
            }
        }
    }
    //node2에서의 거리계산

    if(cost1[node1]>1000000 || cost1[node2]>1000000 || cost1[N]>1000000){
        cout<<"-1"<<'\n';
        return 0;
    }
    int sol=min(cost1[node1]+costv1[node2]+costv2[N],cost1[node2]+costv2[node1]+costv1[N]);
    cout<<sol<<'\n';
}