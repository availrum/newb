#include<iostream>
#include<cmath>
#include<vector>
#define ll long long int
using namespace std;
int main(){ //13021
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    vector<pair<int,int>> vec;
    for(int i=0; i<M; ++i){
        int st, ed;
        cin>>st>>ed;
        vec.push_back({st,ed});
    }
    ll cnt=0;

    bool colored[N+1]={false,};
    for(int i=vec.size()-1; i>=0; --i){
        bool flag=false;
        for(int j=vec[i].first; j<=vec[i].second; ++j){
            if(!colored[j]){
                flag=true;
            }
            colored[j]=true;
        }
        if(!flag) continue;
        ++cnt;
    }
    ll number=pow(2,cnt);
    cout<<number<<'\n';
} 