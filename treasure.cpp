#include<iostream>
#include<algorithm>
using namespace std;
int main(){//1026
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int arr[N],B[N];
    for(int i=0; i<N; ++i){
        cin>>arr[i];
    }
    sort(arr,arr+N);
    for(int i=0; i<N; ++i){
        cin>>B[i];
    }
    sort(B,B+N);
    int sum=0;
    for(int i=0; i<N; ++i){
        sum+=arr[i]*B[N-1-i];
    }
    cout<<sum<<'\n';
}