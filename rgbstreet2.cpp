#include<iostream>
using namespace std;
// 붙어있는 집의 색상과 다르게
int minimum(int a, int b, int c){
    int tmp=a;
    if(tmp>b) tmp=b;
    if(tmp>c) tmp=c;
    return tmp;
}
int main(){//17404
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;
    long int arr[N][N],mini[3][N+1][N+1],sol[N]={0,};
    for(int i=0; i<N; i++){
        for(int j=0; j<3; j++){
            cin>>arr[i][j];
        }
    }
    for(int j=0; j<3; ++j){
        for(int i=0; i<3; ++i) mini[j][N-1][i]=0;
        for(int i=0; i<3; ++i){
            if(j==i){
                mini[j][1][i]=2147483646;
                continue;
            }
            mini[j][1][i]=arr[0][j]+arr[1][i];
        }
        sol[1]=minimum(mini[j][1][0],mini[j][1][1],mini[j][1][2]);
        for(int i=2; i<N; ++i){
            if(i<N-1){
                mini[j][i][0]=min(mini[j][i-1][1]+arr[i][0], mini[j][i-1][2]+arr[i][0]);
                mini[j][i][1]=min(mini[j][i-1][0]+arr[i][1], mini[j][i-1][2]+arr[i][1]);
                mini[j][i][2]=min(mini[j][i-1][0]+arr[i][2], mini[j][i-1][1]+arr[i][2]);
                sol[i]=minimum(mini[j][i][0],mini[j][i][1],mini[j][i][2]);
            }
            else if(i==N-1){
                for(int k=0; k<3; ++k){
                    if(k==j) continue;
                    if(k==0) mini[j][i][k]=min(mini[j][i-1][1],mini[j][i-1][2])+arr[i][k];
                    else if(k==1) mini[j][i][k]=min(mini[j][i-1][0],mini[j][i-1][2])+arr[i][k];
                    else if(k==2) mini[j][i][k]=min(mini[j][i-1][0],mini[j][i-1][1])+arr[i][k];

                    if(sol[i]==0 || sol[i]>mini[j][i][k]) sol[i]=mini[j][i][k];
                }
            }
        }
    }
    
    // cout<<'\n';
    // for(int i=0; i<3; ++i) for(int j=0; j<3; ++j){
    //     cout<<mini[i][N-1][j];
    //     if(j==2) cout<<'\n';
    //     else cout<<' ';
    // }
    // cout<<'\n';

    // cout<<min[N-1][0]<<' '<<min[N-1][1]<<' '<<min[N-1][2]<<'\n';
    cout<<sol[N-1]<<'\n';
}