#include<iostream>
using namespace std;
int main(){ //2744
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string st;
    cin>>st;
    for(int i=0; i<st.length(); ++i){
        if(st[i]>95) st[i]=toupper(st[i]);
        else st[i]=tolower(st[i]);
    }
    cout<<st<<'\n';
}