#include<iostream>
#include<unordered_map>
#include<algorithm>
#define ll long long int
using namespace std;
int main(){//2295
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N,t;
    cin>>N;
    unordered_map<ll,ll> check, checktwosum;
    ll arr[N];
    for(int i=0; i<N; ++i){
        cin>>arr[i];
        ++check[arr[i]];
    }
    ll sol=-1;
    sort(arr,arr+N);
    for(int i=0; i<N; ++i){
        for(int j=i; j<N; ++j){
            if(!checktwosum[arr[i]+arr[j]]){
                ++checktwosum[arr[i]+arr[j]];
            }
        }
    }
    for(int i=0; i<N; ++i){
        for(int j=i+1; j<N; ++j){
            if(checktwosum[arr[j]-arr[i]]) sol=max(sol,arr[j]);
        }
    }
    cout<<sol<<'\n';
}