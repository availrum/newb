#include<iostream>
using namespace std;
int main(){ //11365
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string st;
    while(getline(cin,st)){
        if(st=="END") break;
        for(int i=st.length()-1; i>=0; --i){
            cout<<st[i];
        }
        cout<<'\n';
    }
}