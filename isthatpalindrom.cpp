#include<iostream>
using namespace std;
int dp[2001][2001];
int main(){//10942
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int tmp,arr[N];
    for(int i=0; i<N; ++i){
        cin>>arr[i];
    }

    //홀수인 팰린드롬
    for(int i=0; i<N; ++i){//중심
        for(int j=i; j<N; ++j){//오른쪽방향
            if(i-(j-i)<0) break;//왼쪽이 0을 넘어가면 끝
            else if(2*i-j+1 < j-1 && dp[i-(j-i)+1][j-1]==0) break;
            else if(arr[2*i-j]!=arr[j]) break;
            else dp[2*i-j][j]=1;
        }
    }

    //짝수인 팰린드롬
    for(int i=0; i<N; ++i){//중심
        for(int j=i+1; j<N; ++j){//오른쪽방향
            if(i-(j-i)+1<0) break;//왼쪽이 0을 넘어가면 끝
            else if(2*i-j+2 < j-1 && dp[i-(j-i)+2][j-1]==0) break;
            else if(arr[2*i-j+1]!=arr[j]) break;
            else dp[2*i-j+1][j]=1;
        }
    }

    int M,S,E;
    cin>>M;
    for(int i=0; i<M; ++i){
        cin>>S>>E;
        if(dp[S-1][E-1]) cout<<"1"<<'\n';
        else cout<<"0"<<'\n';
    }
}