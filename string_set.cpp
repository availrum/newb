#include<iostream>
#include<unordered_map>
using namespace std;
int main(){//14425
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M,cnt=0;
    cin>>N>>M;
    unordered_map<string, int> ma;
    string st;
    for(int i=0; i<N; ++i){
        cin>>st;
        ma[st]=1;
    }
    for(int i=0; i<M; ++i){
        cin>>st;
        if(ma[st]==1) ++cnt; 
    }
    cout<<cnt<<'\n';
}