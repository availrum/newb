#include<iostream>
using namespace std;
int main(){ //2670
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    double t, dp[N], max_value=0;
    for(int i=0; i<N; ++i){
        cin>>t;
        if(i==0) dp[i]=t;
        else dp[i]=max(dp[i-1]*t,t);
        max_value=max(max_value,dp[i]);
    }
    cout.precision(3);
    cout<<fixed;
    cout<<max_value<<'\n';
}