#include<iostream>
#include<vector>
#include<stack>
#define ll long long int
using namespace std;
int main(){ //6198
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N,t;
    cin>>N;
    vector<ll> arr(N,0);
    stack<pair<ll,ll>> st;
    for(int i=0; i<N; ++i){
        cin>>t;
        if(st.empty() || st.top().first>t){
            st.push({t,i});
        }
        else{
            while(!st.empty() && st.top().first<=t){
                ll x=st.top().second;
                arr[x]=i-x-1;
                st.pop();
            }
            st.push({t,i});
        }
    }
    while(!st.empty()){
        pair<ll,ll> tmp=st.top();
        st.pop();
        // cout<<tmp.second<<'\n';
        arr[tmp.second]=N-1-tmp.second;
    }
    ll cnt=0;

    for(int i=0; i<N; ++i){
        cnt+=arr[i];
        // cout<<arr[i]<<' ';
    }
    // cout<<'\n';
    cout<<cnt<<'\n';
}