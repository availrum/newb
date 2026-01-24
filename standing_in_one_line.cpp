#include<iostream>
#include<vector>
using namespace std;
int main(){ //1138
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,t;
    cin>>N;
    int arr[N]={0,};
    for(int i=1; i<=N; ++i){
        cin>>t;
        int idx=0;
        for(int j=0; j<N; ++j){
            if(arr[j]==0){
                ++idx;
                if(idx==t+1){
                    arr[j]=i;
                    break;
                }
            }
        }
    }
    for(int i=0; i<N; ++i){
        if(i!=0) cout<<' ';
        cout<<arr[i];
    }
    cout<<'\n';
}