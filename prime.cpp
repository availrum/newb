#include<iostream>
using namespace std;
int main (){//2581
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int M,N;
    cin>>M>>N;
    int arr[N+1]={0,};
    for(int i=2; i*i<=N; ++i){
        for(int j=0; i*j<=N; ++j){
            if(arr[i*j]==0 && (i*i)<=i*j) arr[i*j]=1;
        }
    }
    int sum=0, min=0;
    for(int i=M; i<=N; ++i){
        // cout<<arr[i]<<' '<<i<<'\n';
        if(i==1) continue;
        if(arr[i]==0){
            if(min==0) min=i;
            sum+=i;
        }
    }
    if(sum==0){
        cout<<"-1"<<'\n';
        return 0;
    }
    cout<<sum<<'\n'<<min<<'\n';
}