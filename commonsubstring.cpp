#include<iostream>
using namespace std;
int main(){//5582
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string st1, st2;
    cin>>st1>>st2;
    // pair<int, int>
    int dp[st1.length()+1][st2.length()+1];
    for(int i=0; i<=st1.length(); ++i){
        for(int j=0; j<=st2.length(); ++j){
            // dp[i][j]={0,0};
            dp[i][j]=0;
        }
    }
    // cout<<"  dsdsds   "<<'\n';
    int maxlen=0;
    for(int i=0; i<st1.length(); ++i){
        for(int j=0; j<st2.length(); ++j){
            // if(st1[i]==st2[j]) dp[i+1][j+1].first=max(dp[i+1][j+1].first, dp[i][j].first+1);
            if(st1[i]==st2[j]) dp[i+1][j+1]=max(dp[i+1][j+1], dp[i][j]+1);

            if(maxlen < dp[i+1][j+1]) maxlen = dp[i+1][j+1];
            // cout<<dp[i+1][j+1].second<<' ';

        }
        // cout<<'\n';
    }
    // cout<<dp[st1.length()][st2.length()].second<<'\n';
    cout<<maxlen<<'\n';
}