#include<iostream>
using namespace std;
int dirx[3]={0,1,1};
int diry[3]={1,1,0};
int main(){ //1051
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    int arr[N][M];
    for(int i=0; i<N; ++i){
        string st;
        cin>>st;
        for(int j=0; j<M; ++j){
            arr[i][j]=st[j]-'0';
        }
    }
    int max_value=1;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            for(int k=1; k<N+M; ++k){
                if(i+k>=N) break;
                if(j+k>=M) break;
                int cnt=0;
                for(int l=0; l<3; ++l){
                    if(arr[i][j]==arr[i+dirx[l]*k][j+diry[l]*k]) ++cnt;
                }
                // cout<<cnt<<'\n';
                if(cnt==3){
                    // cout<<i<<' '<<j<<' '<<k+1<<'\n';
                    max_value=max(max_value,(k+1)*(k+1));
                }
            }
            // cout<<arr[i][j]<<' ';
        }
        // cout<<'\n';
    }
    cout<<max_value<<'\n';
}