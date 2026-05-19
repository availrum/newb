#include<iostream>
#include<vector>
using namespace std;
int main(){ //9658
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,t;
    cin>>N;
    vector<int> arr(N+5,-1);
    arr[1]=1; //창영
    arr[2]=0; //상근
    arr[3]=1; //창영
    arr[4]=0; //상근
    
    for(int i=5; i<=N; ++i){
        if(arr[i-1]==1 || arr[i-3]==1 || arr[i-4]==1) arr[i]=0;
        else arr[i]=1;
    }
    // cout<<arr[N]<<'\n';
    if(arr[N]==0) cout<<"SK\n";
    else cout<<"CY\n";
}