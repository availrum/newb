#include<iostream>
#include<vector>
using namespace std;
const int con=1000000;
int main(){ //2011
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string st;
    cin>>st;
    int N=st.length();
    vector<vector<int>> dp(N, vector<int>(2,0));
    bool flag=false;
    for(int i=0; i<N; ++i){
        if(i==0){
            if(st[i]-'0'==0) break;
            else if(st[i]-'0'<=2 && st[i]-'0'>0) dp[i][1]=1; //i번째가 10의자리인 개수
            dp[i][0]=1; //i번째를 하나의 숫자로 친 개수
            if(i==N-1) flag=true;
        }
        else{
            if(st[i]-'0'<=2 && st[i]-'0'>0) dp[i][1]=(dp[i][1]+dp[i-1][0])%con;
            if((st[i]-'0'<=6 && st[i-1]-'0'==2) || (st[i-1]-'0'<2)){
                dp[i][0]=(dp[i][0]+dp[i-1][1])%con;
                if(i==N-1 && dp[i-1][1]!=0) flag=true; //나머지가 0될경우 대비
            }
            if(st[i]-'0'>0) dp[i][0]=(dp[i][0]+dp[i-1][0])%con; //단일숫자는 1부터 시작(A)

            if(i==N-1 && dp[i-1][0]!=0) flag=true; //나머지가 0될경우 대비 근데 죄다 나머지0인경우가 있으면 틀릴거같은데 그런경우가 가능한가?
        }
        // cout<<st[i]<<'\n';
        // cout<<dp[i][0]<<' '<<dp[i][1]<<'\n';
    }
    // int sol=dp[N-1][0];
    if(!flag) cout<<"0\n";
    else cout<<dp[N-1][0]<<'\n';
}