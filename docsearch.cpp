#include<iostream>
#include<unordered_map>
using namespace std;
int main(){//1543
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string st;
    // cin>>st;
    getline(cin,st);
    unordered_map<string,int> check;
    string sol;
    // cin>>sol;
    getline(cin,sol);
    for(int i=0; i<st.length(); ++i){
        string tmp="";
        for(int j=0; j<sol.length(); ++j){
            if(st.length()-(i+j) < sol.length()-j) break;
            else if(st[i+j]!=sol[j]) break;
             
            tmp+=sol[j];
        }
        if(sol==tmp){
            ++check[sol];
            i+=sol.length()-1;
        }

    }
    cout<<check[sol]<<'\n';
}