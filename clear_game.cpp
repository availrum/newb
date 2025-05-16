#include<iostream>
using namespace std;
int main(){//28017
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    int game[N][M];
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cin>>game[i][j];
        }
    }
    int dp[N][M];
    dp[0][0]=game[0][0], dp[0][1]=game[0][1];

    pair<int,int> L_first={game[0][0],0}, L_second={game[0][1],1};
    if(L_first.first>L_second.first) swap(L_first,L_second);

    for(int i=2; i<M; ++i){
        dp[0][i]=game[0][i];
        if(dp[0][i]<L_first.first){
            L_second=L_first;
            L_first={dp[0][i],i};
        }
        else if(dp[0][i]<L_second.first){
            L_second={dp[0][i],i};
        }
    }
    for(int i=1; i<N; ++i){
        for(int j=0; j<M; ++j){
            if(L_first.second!=j){
                dp[i][j]=L_first.first+game[i][j];
            }
            else{
                dp[i][j]=L_second.first+game[i][j];
            }
        }
        L_first={dp[i][0],0}, L_second={dp[i][1],1};
        if(dp[i][0]>dp[i][1]) swap(L_first,L_second);
        for(int k=2; k<M; ++k){
            if(dp[i][k]<L_first.first){
                L_second=L_first;
                L_first={dp[i][k],k};
            }
            else if(dp[i][k]<L_second.first){
                L_second={dp[i][k],k};
            }
        }
    }
    cout<<L_first.first<<'\n';
}