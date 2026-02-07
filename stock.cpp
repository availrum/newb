#include<iostream>
#define ll long long int
using namespace std;
int main(){ //11501
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    for(int tcase=0; tcase<t; ++tcase){
        ll N;
        cin>>N;
        ll arr[N];
        for(int i=0; i<N; ++i){
            cin>>arr[N-1-i];
        }
        ll cur_max=0, money=0;
        for(int i=0; i<N; ++i){
            if(cur_max>arr[i]) money+=(cur_max-arr[i]); 
            cur_max=max(cur_max,arr[i]);
        }
        cout<<money<<'\n';
    }
}