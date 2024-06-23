#include<iostream>
using namespace std;
int main(){//25592
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,t;
    cin>>N;
    for(int i=0; i<N; ++i){
        N-=(i+1);
        t=i+1;
        if(N<0) break;
    }
    if(t%2==0) cout<<abs(N-t-1)<<'\n';
    else cout<<"0"<<'\n';

}