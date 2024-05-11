#include<iostream>
using namespace std;
int main(){//1789
    ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    unsigned long long int S,N;
    int max;
    cin>>S;
    N=S;
    for(int i=1; i<=N; i++){
        if(S>i) S-=i;
        else if(S==i){
            max=i;
            break;
        }
        else {
            max=i-1;
            break;
        }
    }
    cout<<max<<'\n';

}
