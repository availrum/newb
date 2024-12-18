#include<iostream>
#include<algorithm>
using namespace std;
int main(){//2470
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int arr[N]={0,};
    for(int i=0; i<N; ++i) cin>>arr[i];
    sort(arr,arr+N);
    int st=0, ed=N-1;
    int mini1=arr[st], mini2=arr[ed];
    int sum=mini1+mini2;
    long int val=abs(sum);
    while(st<ed){
        sum=arr[st]+arr[ed];
        if(val>abs(sum)){
            val=abs(sum);
            mini1=arr[st];
            mini2=arr[ed];
        }
        if(sum>0){
            --ed;
        }
        else if(sum<0){
            ++st;
        }
        else{
            break;
        }
    }
    cout<<mini1<<' '<<mini2<<'\n';
}