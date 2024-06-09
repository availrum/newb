#include<iostream>
using namespace std;
int arr[129][129];
int cnt0,cnt1;
void quard(int a, int b, int n){
    if(n==1){
        if(arr[a][b]==1) cnt1++;
        else cnt0++;
        return;
    }
    int flag0=0, flag1=0;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(flag0==0 && arr[a+i][b+j]==0) flag0=1;
            if(flag1==0 && arr[a+i][b+j]==1) flag1=1;
        }
    }
    if((flag1+flag0)==1){
        if(arr[a][b]==1) cnt1++;
        else cnt0++;
        return;
    }
    quard(a,b,n/2);
    quard(a,b+n/2,n/2);
    quard(a+n/2,b,n/2);
    quard(a+n/2,b+n/2,n/2);
}
int main(){//2630
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,tmp;
    cin>>N;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j) cin>>arr[i][j];
    }
    quard(0,0,N);
    cout<<cnt0<<'\n'<<cnt1<<'\n';
}