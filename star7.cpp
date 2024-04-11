#include<iostream>
using namespace std;
int main(){
    int N,tmp;
    cin>>N;
    tmp=1;
    for(int i=0; i<N; i++){
        for(int j=0; j<N-tmp; j++){
            cout<<" ";
        }
        for(int j=0; j<tmp-1; j++){
            cout<<"*";
        }
        cout<<"*";
        for(int j=0; j<tmp-1; j++){
            cout<<"*";
        }
        cout<<'\n';
        tmp++;
    }
    tmp=2;
    for(int i=0; i<N-1; i++){
        for(int j=0; j<tmp-1; j++){
            cout<<" ";
        }
        for(int j=0; j<N-tmp; j++){
            cout<<"*";
        }
        cout<<"*";
        for(int j=0; j<N-tmp; j++){
            cout<<"*";
        }
        cout<<'\n';
        tmp++;
    }
}