#include<iostream>
#include<algorithm>
using namespace std;
int main(){ //1015
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int A[N];
    pair<int,int> arr[N];
    for(int i=0; i<N; ++i){
        cin>>arr[i].first;
        arr[i].second=i;
    }
    sort(arr,arr+N);
    for(int i=0; i<N; ++i){
        A[arr[i].second]=i;
    }
    for(int i=0; i<N; ++i){
        if(i!=0) cout<<' ';
        cout<<A[i];
    }
    cout<<'\n';
}