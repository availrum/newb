#include<iostream>
using namespace std;
int main(){//11722
    int N;
    cin>>N;
    int arr[N+1], val[N+1]={0,}, idx=0;
    for(int i=N; i>=1; --i) cin>>arr[i];
    arr[0]=0;
    for(int i=1; i<=N; ++i){
        if(arr[i]>val[idx]){    //이번에 넣는 값이 개수 최대의 값보다 크면
            ++idx;
            val[idx]=arr[i];
            continue;
        }
        int st=1,ed=idx,mid=(st+ed)/2;
        while(st<=ed){
            mid=(st+ed)/2;
            if(arr[i]<=val[mid]) ed=mid-1;
            else st=mid+1;
            // else break;
        }
        val[st]=arr[i];
    }
    // for(int i=0; i<=idx; i++) cout<<"cnt="<<i<<", val="<<val[i]<<'\n';
    cout<<idx<<'\n';
}