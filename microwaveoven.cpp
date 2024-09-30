#include<iostream>
using namespace std;
int main(){//10162
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T,A=300,B=60,C=10,cnt=0;
    cin>>T;
    if(T%10!=0){
        cout<<"-1\n";
        return 0;
    }
    cout<<T/A<<' ';
    T%=A;
    cout<<T/B<<' ';
    T%=B;
    cout<<T/C<<'\n';
}