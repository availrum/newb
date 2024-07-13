#include<iostream>
using namespace std;
int main(){//2920
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,cnt=0,cnti=0;
    for(int i=0; i<8; ++i){
        cin>>n;
        if(n==i+1) ++cnt;
        else if(n==8-i) ++cnti;
    }
    if(cnt==8) cout<<"ascending"<<'\n';
    else if(cnti==8) cout<<"descending"<<'\n';
    else cout<<"mixed"<<'\n';
}