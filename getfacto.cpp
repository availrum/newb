#include<iostream>
using namespace std;
int main(){//2501
    ios::sync_with_stdio(false);
    int N,K;
    cin>>N>>K;
    int i=1;
    while(i<=N && K!=0){
        if(N%i==0) --K;
        if(K==0) break;
        ++i;
    }
    if(K==0) cout<<i<<'\n';
    else cout<<"0"<<'\n';
}