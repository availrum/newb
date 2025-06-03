#include<iostream>
#include<cmath>
using namespace std;
int main(){//1699
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int arr[N+1]={0,};
    for(int i=1; i<=N; ++i) arr[i]=2147483647;
    
    for(int i=1; i<=N; ++i){
        int x=pow(i,0.5);
        for(int j=1; j<=x; ++j){
            arr[i]=min(arr[i],arr[i-j*j]+1);
        }
    }
    cout<<arr[N]<<'\n';
}