#include<iostream>
#include<unordered_map>
#define ll long long int
using namespace std;
int main(){ //11652
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,t;
    cin>>N;
    pair<ll,int> max_cnt={0,0};
    unordered_map<ll,int> cnt;
    for(int i=0; i<N; ++i){
        cin>>t;
        ++cnt[t];
        if(max_cnt.second<cnt[t]) max_cnt={t,cnt[t]};
        else if(max_cnt.second==cnt[t] && max_cnt.first>t) max_cnt={t,cnt[t]};
    }
    cout<<max_cnt.first<<'\n';
} 