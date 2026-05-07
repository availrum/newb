#include<iostream>
#include<vector>
using namespace std;
int main(){ //10211
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int tcase=0; tcase<T; ++tcase){
        int N,t;
        cin>>N;
        vector<int> arr(N,0);
        cin>>arr[0];
        int max_value=arr[0];
        for(int i=1; i<N; ++i){
            cin>>t;
            arr[i]=max(arr[i-1]+t,t);
            max_value=max(max_value,arr[i]);
        }
        cout<<max_value<<'\n';
    }
}