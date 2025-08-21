#include<iostream>
using namespace std;
int main(){ //32141
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,H;
    cin>>N>>H;
    int card[N];
    for(int i=0; i<N; ++i){
        cin>>card[i];
    }
    int idx;
    for(int i=0; i<N; ++i){
        H-=card[i];
        idx=i+1;
        if(H<=0) break;
    }
    if(H<=0) cout<<idx<<'\n';
    else cout<<"-1"<<'\n';
}