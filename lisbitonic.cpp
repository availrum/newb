#include<iostream>
using namespace std;
int main(){//11054
    int N;
    cin>>N;
    int arr[N+2], cnt[N+2]={0,}, cntb[N+2]={0,}, max=0;
    for(int i=1; i<=N; ++i) cin>>arr[i];
    cnt[0]=0,cntb[N+1]=0;
    arr[0]=0,arr[N+1]=0;
    for(int i=1; i<=N; ++i){
        for(int j=i-1; j>=0; --j){
            if(arr[i]>arr[j] && cnt[i]<=cnt[j]) cnt[i]=cnt[j]+1;
        }
        for(int j=N-i+2; j<=N+1; ++j){
            if(N-i+1==0) break;
            if(arr[N-i+1]>arr[j] && cntb[N-i+1]<=cntb[j]) cntb[N-i+1]=cntb[j]+1;
        }
    }
    for(int i=1; i<=N; ++i) if(max<cnt[i]+cntb[i]-1) {
        max=cnt[i]+cntb[i]-1;
    }
    cout<<max<<'\n';
    // for(int i=1; i<=N; ++i) cout<<cnt[i]<<' ';
    // cout<<'\n';
    // for(int i=1; i<=N; ++i) cout<<cntb[i]<<' ';
    // cout<<'\n';
}