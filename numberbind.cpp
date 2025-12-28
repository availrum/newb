#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){//1744
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int arr[N];
    for(int i=0; i<N; ++i){
        cin>>arr[i];
    }
    sort(arr,arr+N);
    int sum=0;
    vector<vector<int>> val(N,vector<int>(2,0));
    val[0][0]=arr[0];
    val[0][1]=arr[0];
    for(int i=1; i<N; ++i){
        if(i==1){
            val[i][0]=arr[i-1]+arr[i];
            val[i][1]=arr[i-1]*arr[i];
        }
        else{
            val[i][0]=max(val[i-1][0],val[i-1][1])+arr[i];
            val[i][1]=max(val[i-2][0],val[i-2][1])+max(arr[i-1]+arr[i],arr[i-1]*arr[i]);
        }
    }
    cout<<max(val[N-1][0],val[N-1][1])<<'\n';
}