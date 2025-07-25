#include<iostream>
#include<vector>
#include<cmath>
#include<unordered_map>
#define ll long long int
using namespace std;
int main(){ //11689
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N;
    cin>>N;
    ll root=pow(N,0.5);
    ll droot=pow(root,0.5);
    ll arr[root+1]={0,};

    for(int i=2; i<=droot; ++i){
        for(int j=2; j*i<=root; ++j){
            arr[i*j]=1;
        }
    }
    vector<ll> prime;
    for(int i=2; i<=root; ++i){
        if(arr[i]==0){
            prime.push_back(i);
        }
    }

    ll cnt=N, tmp=N;
    unordered_map<ll,ll> check;
    vector<ll> divide;
    for(int i=0; i<prime.size(); ++i){
        while(tmp%prime[i]==0 && tmp>=prime[i]){
            if(!check[prime[i]]) divide.push_back(prime[i]);
            ++check[prime[i]];
            tmp/=prime[i];
        }
        // cout<<tmp<<'\n';
    }
    if(!check[tmp] && tmp!=1){
        divide.push_back(tmp);
        ++check[tmp];
    }
    for(int i=0; i<divide.size(); ++i){
        cnt/=divide[i];
        cnt*=(divide[i]-1);
    }
    // for(int i=0; i<divide.size(); ++i) cout<<divide[i]<<' ';
    // cout<<'\n';
    cout<<cnt<<'\n';
} 