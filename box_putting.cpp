#include<iostream>
#include<vector>
using namespace std;
int main(){ //1965
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    vector<int> arr(N);
    for(int i=0; i<N; ++i){
        cin>>arr[i];
    }
    int max_cnt=1;
    vector<int> dp(N,1);
    for(int i=0; i<N; ++i){
        for(int j=i-1; j>=0; --j){
            if(arr[i]>arr[j]) dp[i]=max(dp[i], dp[j]+1);
        }
        max_cnt=max(max_cnt,dp[i]);
    }
    cout<<max_cnt<<'\n';
}