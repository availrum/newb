#include<iostream>
using namespace std;
int main(){//1439
    ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    int cntf=0,cntb=1;
    string S;
    cin>>S;
    for(int i=1; i<S.length(); i++){
        if(S[0]!=S[i] && S[i-1]!=S[i]) cntf++;
        
        else if(S[0]==S[i] && S[i-1]!=S[i]) cntb++;
    }
    if(cntf>cntb) cout<<cntb<<'\n';
    else cout<<cntf<<'\n';
    // cout<<cntf<<' '<<cntb<<'\n';
}
