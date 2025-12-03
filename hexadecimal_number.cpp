#include<iostream>
using namespace std;
int main(){ //1550
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string st;
    cin>>st;
    int sol=0;
    int idx=1;
    for(int i=st.length()-1; i>=0; --i){
        if(st[i]<'A') sol+=idx*(st[i]-'0');
        else sol+=idx*(st[i]-'A'+10);
        idx*=16;
    }
    cout<<sol<<'\n';
}