#include<iostream>
using namespace std;
int main(){//9251
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string st1,st2;
    cin>>st1>>st2;
    int dp[st1.length()+1][st2.length()+1];
    for(int i=0; i<=st1.length(); ++i) for(int j=0; j<=st2.length(); ++j) dp[i][j]=0;
    for(int i=1; i<=st1.length(); ++i){
        for(int j=1; j<=st2.length(); ++j){
            if(st1[i-1]==st2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    // for(int i=1; i<=st1.length(); ++i){
    //     for(int j=1; j<=st2.length(); ++j) cout<<dp[i][j]<<' ';
    //     cout<<'\n';
    // }
    int x=st1.length(), y=st2.length(), cnt=dp[st1.length()][st2.length()];
    cout<<cnt<<'\n';
    string st="";
    while(cnt && x>=0 && y>=0){
        if(st1[x-1]==st2[y-1]){
            st=st1[x-1]+st;
            --x;
            --y;
            --cnt;
        }
        else if(dp[x-1][y]>dp[x][y-1]) --x;
        else --y;
    }
    if(dp[st1.length()][st2.length()]) cout<<st<<'\n';
}