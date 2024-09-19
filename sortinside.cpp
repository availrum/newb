#include<iostream>
#include<algorithm>
using namespace std;
int main(){//1427
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long int N,t=1,num=1;
    cin>>N;
    while(t<=N){
        ++num;
        t*=10;
    }
    int arr[num];
    for(int i=0; i<num; ++i){
        arr[i]=N/t;
        N-=arr[i]*t;
        t/=10;
    }
    sort(arr,arr+num);
    for(int i=num-1; i>0; --i) cout<<arr[i];
    cout<<'\n';
}