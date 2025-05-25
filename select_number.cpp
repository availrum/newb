#include<iostream>
#include<algorithm>
#define ll long long int
using namespace std;
int main(){//2230
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N,M;
    cin>>N>>M;
    ll seq[N];
    for(int i=0; i<N; ++i){
        cin>>seq[i];
    }
    sort(seq,seq+N);
    ll st=0, ed=0, mindif=2147483647;
    while(st<N){
        if(seq[ed]-seq[st]>=M){
            mindif=min(mindif,seq[ed]-seq[st]);
            ++st;
            ed=st;
        }
        else{
            if(ed<N) ++ed;
            else break;
        }
    }
    cout<<mindif<<'\n';
}