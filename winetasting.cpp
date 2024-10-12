#include<iostream>
using namespace std;
int main(){//2156
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int mwine[N+1];
    int wine[N+1];
    for(int i=0; i<N; ++i) cin>>wine[i];
    mwine[0]=wine[0];
    if(N>1) mwine[1]=wine[0]+wine[1];
    if(N>2) mwine[2]=max(mwine[1],max(wine[0]+wine[2],wine[1]+wine[2]));
    for(int i=3; i<N; ++i){
        mwine[i]=max(mwine[i-3]+wine[i-1]+wine[i], max(mwine[i-1], mwine[i-2]+wine[i]));
    }
    cout<<mwine[N-1]<<'\n';
}