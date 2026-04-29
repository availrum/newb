#include<iostream>
#include<vector>
#define ll long long int
using namespace std;
int main(){ //13699
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,t;
    cin>>n;
    vector<ll> arr(n+1,0);
    arr[0]=1;

    for(int i=1; i<=n; ++i){
        ll tmp=0;
        for(int j=i-1; j>=0; --j){
            tmp+=arr[j]*arr[i-1-j];
        }
        arr[i]=tmp;
    }
    cout<<arr[n]<<'\n';
}