#include<iostream>
#include<algorithm>
using namespace std;
int main(){//11656
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string st;
    cin>>st;
    string str[st.length()];
    for(int i=0; i<st.length(); ++i){
        string tmp="";
        for(int j=i; j<st.length(); ++j){
            tmp+=st[j];
        }
        str[i]=tmp;
    }
    sort(str,str+st.length());
    for(int i=0; i<st.length(); ++i){
        cout<<str[i]<<'\n';
    }
}