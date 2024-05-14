#include<iostream>
using namespace std;
int main(){//4101
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    while(true){
        cin>>N>>M;
        if(N==0 && N==M) break;
        if(N>M) cout<<"Yes"<<'\n';
        else cout<<"No"<<'\n';
    }
    return 0;
}