#include<iostream>
using namespace std;
int main(){//2440
    int N;
    cin>>N;
    for(int i=0; i<N; ++i){
        for(int j=N-i; j>=1; --j) cout<<"*";
        cout<<'\n';
    }
}