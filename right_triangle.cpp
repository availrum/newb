#include<iostream>
#include<vector>
#include<unordered_map>
#define ll long long int
using namespace std;
int main(){ //3000
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    vector<pair<int,int>> vec;
    unordered_map<int,ll> numx, numy;
    for(int i=0; i<N; ++i){
        int x,y;
        cin>>x>>y;
        vec.push_back({x,y});
        ++numx[x];
        ++numy[y];
    }
    ll sol=0;
    for(int i=0; i<N; ++i){
        sol+=(numx[vec[i].first]-1)*(numy[vec[i].second]-1);
    }
    cout<<sol<<'\n';
}