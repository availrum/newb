#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int S, cnt=0;
void btr(vector<int>& arr, int n, int sum){
    sum+=arr[n];
    if(sum==S){
        ++cnt; 
        // cout<<sum<<' '<<S<<'\n';
    }
    for(int i=n+1; i<arr.size(); ++i){
        btr(arr,i,sum);
    }
}
int main(){ //1182
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N>>S;
    vector<int> arr(N,0);
    for(int i=0; i<N; ++i){
        cin>>arr[i];
    }
    for(int i=0; i<N; ++i) btr(arr,i,0);
    cout<<cnt<<'\n';
}