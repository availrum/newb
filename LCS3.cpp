#include<iostream>
#include<vector>
using namespace std;
int main(){ //1958
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string st[3];
    cin>>st[0]>>st[1]>>st[2];
    int n=st[0].length(), m=st[1].length(), l=st[2].length(); 
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(l+1,0)));
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            for(int k=1; k<=l; ++k){
                if(st[0][i-1]==st[1][j-1] && st[1][j-1]==st[2][k-1]){
                    dp[i][j][k]=dp[i-1][j-1][k-1]+1;
                }
                else dp[i][j][k]=max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
            }
        }
    }
    cout<<dp[n][m][l]<<'\n';
}