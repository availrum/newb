#include<iostream>
#include<unordered_map>
using namespace std;
int main(){//9095
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,t,tmp=2;
    unordered_map<int,int> ma;
    cin>>t;
    ma[0]=1;
    ma[1]=2;
    ma[2]=4;
    for(int j=0; j<t; ++j){
        cin>>N;
        if(tmp>N-1){
            cout<<ma[N-1]<<'\n';
            continue;
        }
        for(int i=3; i<N; i++) ma[i]=ma[i-1]+ma[i-2]+ma[i-3];
        cout<<ma[N-1]<<'\n';
    }
}