#include<iostream>
#include<queue>
#define ll long long int
using namespace std;
int main(){ //15903
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m,t;
    cin>>n>>m;
    priority_queue<ll,vector<ll>,greater<ll>> qu;
    for(int i=0; i<n; ++i){
        cin>>t;
        qu.push(t);
    }
    for(int i=0; i<m; ++i){
        ll num1=qu.top();
        qu.pop();
        ll num2=qu.top();
        qu.pop();
        ll summation=num1+num2;
        qu.push(summation);
        qu.push(summation);
    }
    ll score=0;
    while(!qu.empty()){
        score+=qu.top();
        qu.pop();
    }
    cout<<score<<'\n';
}