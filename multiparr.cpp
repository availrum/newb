#include<iostream>
using namespace std;
int main(){//2740
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M,K;
    cin>>N>>M;
    int arr1[N][M];
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cin>>arr1[i][j];
        }
    }

    cin>>M>>K;
    int arr2[M][K];
    for(int i=0; i<M; ++i){
        for(int j=0; j<K; ++j){
            cin>>arr2[i][j];
        }
    }

    int tmp;
    int sol[N][K];
    for(int i=0; i<N; ++i){
        for(int j=0; j<K; ++j){
            sol[i][j]=0;
        }
    }

    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            for(int k=0; k<K; ++k){
                sol[i][k]+=arr1[i][j]*arr2[j][k];
            }
        }
    }

    for(int i=0; i<N; ++i){
        for(int j=0; j<K; ++j){
            cout<<sol[i][j];
            if(j!=K-1) cout<<' ';
            else cout<<'\n';
        }
    }
}