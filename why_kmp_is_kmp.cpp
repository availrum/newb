#include<iostream>
using namespace std;
int main(){ //2902
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string st;
    cin>>st;
    string answer="";
    for(int i=0; i<st.length(); ++i){
        if(isalpha(st[i])&& st[i]<97) answer+=st[i];
    }
    cout<<answer<<'\n';
}