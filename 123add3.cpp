#include<iostream>
#include<vector>
#define ll long long int
using namespace std;
int main(){ //15988
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    vector<ll> arr(1000001,0);
    const ll divi=1000000009;
    arr[0]=0;
    arr[1]=1;
    arr[2]=2;
    arr[3]=4;
    for(int tcase=0; tcase<T; ++tcase){
        int N;
        cin>>N;
        if(arr[N]){
            cout<<arr[N]<<'\n';
            continue;
        }
        for(int i=4; i<=N; ++i){
            if(arr[i]) continue;
            arr[i]=((arr[i-1])%divi+(arr[i-2])%divi+(arr[i-3])%divi)%divi;
        }
        cout<<arr[N]<<'\n';
        // for(int i=1; i<=N; ++i){
        //     cout<<arr[i]<<' ';
        // } cout<<'\n';
    }
}