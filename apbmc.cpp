#include<iostream>
using namespace std;
int main(){//31403
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int A,B,C,tmp;
    cin>>A>>B>>C;
    string st="",tmp1=to_string(A),tmp2=to_string(B);
    cout<<A+B-C<<'\n';
    for(int i=0; i<tmp1.length(); ++i) st+=tmp1[i];
    for(int i=0; i<tmp2.length(); ++i) st+=tmp2[i];
    tmp=stoi(st);
    cout<<tmp-C<<'\n';
}