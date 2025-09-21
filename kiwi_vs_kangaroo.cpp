#include<iostream>
using namespace std;
int main(){ //15177
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string st, st1="kangaroo", st2="kiwibird";
    cin>>st;
    int kangaroo=0, kiwi=0;
    int kang[130]={0,}, kiw[130]={0,};
    for(int i=0; i<8; ++i){
        ++kang[toupper(st1[i])];
        ++kiw[toupper(st2[i])];
    }
    // cout<<st<<'\n';
    for(int i=0; i<st.length(); ++i){
        if(kang[toupper(st[i])]) kangaroo+=kang[toupper(st[i])];
        if(kiw[toupper(st[i])]) kiwi+=kiw[toupper(st[i])];
    }
    // cout<<kangaroo<<' '<<kiwi<<'\n';
    if(kangaroo==kiwi) cout<<"Feud continues\n";
    else if(kangaroo>kiwi) cout<<"Kangaroos\n";
    else cout<<"Kiwis\n";
}