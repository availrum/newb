#include<iostream>
using namespace std;
int main(){ //10025
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,K;
    cin>>N>>K;
    pair<int,int> bucket[N];
    int max_cordinate=-1;
    for(int i=0; i<N; ++i){
        cin>>bucket[i].first>>bucket[i].second;
        max_cordinate=max(max_cordinate,bucket[i].second);
    }
    int coordinate[max_cordinate+1]={0,};
    for(int i=0; i<N; ++i){
        coordinate[bucket[i].second]=bucket[i].first;
    }

    int lft=0, rgt=0,ice=0;
    for(rgt=0; rgt<=min(2*K, max_cordinate); ++rgt){
        ice+=coordinate[rgt];
    }
    // cout<<rgt<<'\n';
    int max_ice=ice;

    for(rgt=2*K+1; rgt<=max_cordinate; ++rgt){
        
        ice+=coordinate[rgt];
        ice-=coordinate[lft];
        ++lft;
        max_ice=max(max_ice,ice);
    }
    cout<<max_ice<<'\n';
}