#include<iostream>
using namespace std;
int main(){ //11055
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int arr[N];
    int dp[N]={0,};
    int max_value=0;
    for(int i=0; i<N; ++i){
        cin>>arr[i];
        dp[i]=arr[i];
        max_value=max(max_value,arr[i]);
    }
    for(int i=1; i<N; ++i){
        for(int j=i-1; j>=0; --j){
            if(arr[i]>arr[j] && dp[i]<dp[j]+arr[i]){
                dp[i]=dp[j]+arr[i];
                max_value=max(dp[i],max_value);
            }
        }
    }
    cout<<max_value<<'\n';
}