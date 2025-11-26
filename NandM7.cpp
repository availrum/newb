#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N,M;
void rec(int* arr, int n, vector<int> seq){
    if(seq.size()==M){
        for(int i=0; i<M; ++i){
            cout<<seq[i];
            if(i!=M-1) cout<<' ';
            else cout<<'\n';
        }
        return;
    }
    for(int i=0; i<N; ++i){
        seq.push_back(arr[i]);
        rec(arr,n,seq);
        seq.pop_back();
    }
}
int main(){ //15656
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    int arr[N];
    vector<int> seq;
    for(int i=0; i<N; ++i){
        cin>>arr[i];
    }
    sort(arr,arr+N);
    rec(arr,0,seq);
}