#include<iostream>
#include<vector>
using namespace std;
int main(){ //18353
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    vector<int> arr(N),dp(N,1);
    for(int i=0; i<N; ++i){
        cin>>arr[i];
    }
    int max_value=0;
    for(int i=0; i<N; ++i){
        for(int j=i-1; j>=0; --j){
            if(arr[i]<arr[j]) dp[i]=max(dp[i],dp[j]+1);
        }
        max_value=max(max_value,dp[i]);
    }
    cout<<N-max_value<<'\n';
}