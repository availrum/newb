#include<iostream>
using namespace std;
int main(){ //1094
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int X;
    cin>>X;
    string st="";
    while(X){
        if(X%2==1) st+="1";
        else st+="0";
        X/=2;
    }
    int cnt=0;
    for(int i=0; i<st.length(); ++i){
        if(st[i]=='1') ++cnt;
    }
    // cout<<st<<'\n';
    cout<<cnt<<'\n';
}