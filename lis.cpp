#include<iostream>
using namespace std;
int main(){//11053
    int N;
    cin>>N;
    int arr[N+1], cnt[N+1]={0,}, max=0;
    for(int i=1; i<=N; ++i) cin>>arr[i];
    cnt[0]=0;
    arr[0]=0;
    for(int i=1; i<=N; ++i){
        for(int j=i-1; j>=0; --j){
            if(arr[i]>arr[j] && cnt[i]<=cnt[j]) cnt[i]=cnt[j]+1;
        }
    }
    for(int i=1; i<=N; ++i) if(max<cnt[i]) max=cnt[i];
    //cout<<cnt[i]<<'\n';
    cout<<max<<'\n';

}