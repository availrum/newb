#include<iostream>
using namespace std;
int main(){//11727
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,t;
    cin>>N;
    int arr[N];
    arr[0]=1;
    arr[1]=3; // arr[2]=5, arr[3]=11;
    for(int i=2; i<N; i++) arr[i]=((2*(arr[i-2]%10007))%10007+(arr[i-1])%10007)%10007;
    cout<<arr[N-1]<<'\n';
}