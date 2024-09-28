#include<iostream>
using namespace std;
void recursion(string &s, int l, int r,int cnt){
    if(l >= r){
        cout<<"1 "<<cnt<<'\n';
        return;
    }
    else if(s[l] != s[r]){
        cout<<"0 "<<cnt<<'\n';
        return;
    }
    else recursion(s, l+1, r-1,cnt+1);
}
int main(){//25501
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    string st;
    for(int i=0; i<T; ++i){
        cin>>st;
        recursion(st,0,st.length()-1,1);
    }
}