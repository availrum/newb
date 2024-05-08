#include<iostream>
int check(int a, int b){
    return a>b ? a:b;
}
using namespace std;
int main(){//2720
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    int T,C,N;
    cin>>T;
    for(int i=0; i<T; i++){
        int qu=0,di=0,ni=0,pe=0;
        cin>>C;
        N=C;
        if(N>=25){
            qu+=N/25;
            N=N%25;
        }
        if(N>=10){
            di+=N/10;
            N=N%10;
        }
        if(N>=5){
            ni+=N/5;
            N=N%5;
        }
        pe+=N;
        cout<<qu<<' '<<di<<' '<<ni<<' '<<pe<<'\n';
    }
}