#include<iostream>
using namespace std;
int main(){//2458
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    int arr[N+1][N+1];
    for(int i=0; i<=N; ++i){
        for(int j=0; j<=N; ++j){
            arr[i][j]=100000001;
            if(i==j) arr[i][j]=0;
        }
    }
    int a,b;
    for(int i=0; i<M; ++i){
        cin>>a>>b;
        arr[a][b]=1;
    }
    //i to k (mid j)
    for(int j=1; j<=N; ++j){
        for(int i=1; i<=N; ++i){
            for(int k=1; k<=N; ++k){
                if(arr[i][k]>arr[i][j]+arr[j][k]) arr[i][k]=arr[i][j]+arr[j][k];
            }
        }
    }
    int sol=0;
    for(int i=1; i<=N; ++i){
        bool flag=false;
        for(int j=1; j<=N; ++j){
            // if(arr[i][j]<100000000) cout<<arr[i][j];
            // else cout<<"-1";
            // if(j==N) cout<<'\n';
            // else cout<<' ';
            if(arr[i][j]>100000000 && arr[j][i]>100000000){
                flag=true;
                break;
            }
        }
        if(!flag) ++sol;
    }
    cout<<sol<<'\n';
}