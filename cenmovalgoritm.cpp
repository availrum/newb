#include<iostream>
using namespace std;
int main(){//2903
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,t=1;
    cin>>N;
    //상자수 1>4(2*2)>16(4*4)>64(8*8)>256(16*16)>...
    for(int i=0; i<N; ++i) t*=2;
    cout<<(t+1)*(t+1)<<'\n';
}