#include<iostream>
#include<map>
using namespace std;
int main(){//17219
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    string st,stp;
    map<string,string> pwd;
    cin>>N>>M;
    for(int i=0; i<N; i++){
        cin>>st>>stp;
        pwd[st]=stp;
    }
    for(int i=0; i<M; i++){
        cin>>st;
        cout<<pwd[st]<<'\n';
    }
    return 0;
}
