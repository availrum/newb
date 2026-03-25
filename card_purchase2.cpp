#include<iostream>
#include<vector>
using namespace std;
int main(){ //16194
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    vector<int> arr(N+1);
    vector<int> min_cost(N+1,100000001);
    min_cost[0]=0;
    for(int i=1; i<=N; ++i){
        cin>>arr[i];
        for(int j=1; i*j<=N; ++j){
            min_cost[i*j]=min(min_cost[i*j],j*arr[i]);
        }
    }

    for(int i=1; i<=N; ++i){
        for(int j=i; j>=1; --j){
            min_cost[i]=min(min_cost[i], min_cost[i-j]+arr[j]);
        }
    }
    cout<<min_cost[N]<<'\n';
}