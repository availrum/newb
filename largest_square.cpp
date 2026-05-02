#include<iostream>
#include<vector>
using namespace std;
int dirx[3]={0,1,1};
int diry[3]={1,1,0};
int main(){ //4915
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int>(m));
    vector<vector<int>> dp(n,vector<int>(m,0));
    for(int i=0; i<n; ++i){
        string st;
        cin>>st;
        for(int j=0; j<st.length(); ++j){
            arr[i][j]=st[j]-'0';
        }
    }
    // 1000*1000 > 1,000,000 > nlogn 정도까지 가능할듯? 약 *100번까지 가능
    int max_triangle=0;
    for(int i=n-1; i>=0; --i){
        for(int j=m-1; j>=0; --j){
            if(arr[i][j]==1){
                int cnt=0;
                for(int k=0; k<3; ++k){
                    int x=i+dirx[k];
                    int y=j+diry[k];
                    if(x<0 || x>=n || y<0 || y>=m) continue;
                    else if(!arr[x][y]) continue;
                    ++cnt;
                }
                if(cnt<3) dp[i][j]=1;
                else dp[i][j]=min(dp[i+1][j], min(dp[i+1][j+1],dp[i][j+1]))+1;
                max_triangle=max(max_triangle,dp[i][j]);
            }
        }
    }
    // for(int i=0; i<n; ++i){
    //     for(int j=0; j<m; ++j){
    //         cout<<dp[i][j]<<' ';
    //     }cout<<'\n';
    // }
    cout<<max_triangle*max_triangle<<'\n';
}