#include<iostream>
using namespace std;
int main(){//11653
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    if(N==1) return 0;
    int i=2;
    while(N>1){
        if(N%i==0){
            cout<<i<<'\n';
            N/=i;
            continue;
        }
        ++i;
    }
}