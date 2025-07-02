#include<iostream>
using namespace std;
int main(){ //15565
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,K;
    cin>>N>>K;
    int doll[N];
    for(int i=0; i<N; ++i){
        cin>>doll[i];
    }
    int lft=0, rgt=0;
    int lion=0, maximum_size=N+1;
    if(doll[lft]==1) ++lion;
    while(lft<N){
        if(lion>=K){
            maximum_size=min(maximum_size, rgt-lft+1);
            if(doll[lft]==1) --lion;
            ++lft;
        }
        else if(rgt<N-1){
            ++rgt;
            if(doll[rgt]==1) ++lion;
        }
        else break;
    }
    if(maximum_size!=N+1) cout<<maximum_size<<'\n';
    else cout<<"-1"<<'\n';
}