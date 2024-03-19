#include<iostream>
using namespace std;
int main(){//2292
    long long int N,shell=1,shellsize=6;
    cin>>N;
    if(N==1){
        cout<<"0"<<'\n';
        return 0;
    }
    for(int i=1; i<=N; i++){
        shell+=(i-1)*shellsize;
        if(shell>=N){
            cout<<i<<'\n';
            return 0;
        }
        // cout<<shell<<'\n';
    }
    return 0;
}