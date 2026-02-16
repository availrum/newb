#include<iostream>
using namespace std;
int main(){ //2847
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int arr[N];
    for(int i=0; i<N; ++i){
        cin>>arr[i];
    }
    int cnt=0, bef=arr[N-1];
    for(int i=N-2; i>=0; --i){
        if(arr[i]>=bef){
            cnt+=(arr[i]-bef+1);
            --bef;
        }
        else bef=arr[i];
    }
    cout<<cnt<<'\n';
}