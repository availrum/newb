#include<iostream>
using namespace std;
int K,cnt;
void merge(int p,int q,int r, int *arr){
    int i=p, j=q+1, t=0, tmp[r+1];
    if(cnt==K) return;
    while(i<=q && j<=r){
        if(arr[i]<=arr[j]){
            tmp[t]=arr[i];
            ++t;
            ++i;
        }
        else{
            tmp[t]=arr[j];
            ++t;
            ++j;
        }
    }
    while(i<=q){
        tmp[t]=arr[i];
        ++t;
        ++i;
    }
    while(j<=r){
        tmp[t]=arr[j];
        ++t;
        ++j;
    }
    i=p,t=0;
    while(i<=r){
        ++cnt;
        arr[i]=tmp[t];
        if(cnt==K){
            cout<<arr[i]<<'\n';
            return;
        }
        ++i;
        ++t;
        // cout<<'\n';
        // cout<<"arr[i]="<<arr[i]<<", cnt="<<cnt<<'\n';
        // if(cnt==K){
        //     cout<<arr[i]<<'\n';
        //     return;
        // }
    }
}
void msort(int p, int r, int *arr){
    if(p<r){
        int q;
        q=(p+r)/2;
        msort(p,q,arr);
        msort(q+1,r,arr);
        merge(p,q,r,arr);
    }
}
int main(){//24060
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N>>K;
    int arr[N+1]={0,};
    for(int i=0; i<N; ++i){
        cin>>arr[i];
    }
    msort(0,N-1,arr);
    if(cnt<K) cout<<"-1"<<'\n';
}