#include<iostream>
using namespace std;
int main(){//11660
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    int arr[N][N]={0,},sum[N][N]={0,};
    for(int i=0; i<N; ++i) for(int j=0; j<N; ++j){
        cin>>arr[i][j];
        if(j==0){
            sum[i][j]=arr[i][j];
        }
        else sum[i][j]=sum[i][j-1]+arr[i][j];
    }
    for(int i=0; i<M; ++i){
        int stx,sty,edx,edy;
        cin>>stx>>sty>>edx>>edy;
        int tot=0;
        for(int j=stx-1; j<=edx-1; ++j){
            if(sty!=1) tot+=(sum[j][edy-1]-sum[j][sty-2]);
            else tot+=sum[j][edy-1];
        }
        cout<<tot<<'\n';
    }
    // cout<<'\n';
    // for(int i=0; i<N; ++i) cout<<sum[i][N-1]<<'\n';
}