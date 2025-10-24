#include<iostream>
using namespace std;
int main(){ //11052
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int arr[N+1]={0,};
    int max_cost[N+1];
    for(int i=1; i<=N; ++i){
        cin>>arr[i];
        max_cost[i]=arr[i];
    }
    for(int i=1; i<=N; ++i){
        for(int j=1; i+j<=N; ++j){
            max_cost[i+j]=max(max_cost[i+j], max_cost[j]+arr[i]);
        }
    }
    cout<<max_cost[N]<<'\n';
}