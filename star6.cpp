#include<iostream>
using namespace std;
int main(){ //2443
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,t;
    cin>>N;
    for(int i=0; i<N; ++i){
        for(int j=0; j<i; ++j) cout<<' ';
        for(int j=0; j<N-i; ++j) cout<<"*";
        for(int j=0; j<N-1-i; ++j) cout<<"*";
        cout<<'\n';
    }
}