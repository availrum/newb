#include<iostream>
using namespace std;
int main(){//17987
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string st;
    cin>>st;
    string str="AWAWHOO";
    while(str.length()<=st.length()){
        str+="O";
    }
    cout<<str<<'\n';
}