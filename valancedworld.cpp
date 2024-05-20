#include<iostream>
#include<stack>
using namespace std;
int main(){//4949
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    string st;
    while(true){
        stack<char> stac;
        int det=0;
        getline(cin,st);
        if(st==".") break;
        for(int i=0; i<st.length(); i++){
            if(st[i]=='[' || st[i]=='(') stac.push(st[i]);
            else if(stac.empty()){
                if(st[i]==')' || st[i]==']'){
                    det++;
                    break;
                }
                if(st[i]=='[' || st[i]=='(') stac.push(st[i]);
                continue;
            }
            else if(stac.top()=='['){
                if(st[i]==']') stac.pop();
                else if(st[i]==')'){
                    det++;
                    break;
                }
                continue;
            }
            else if(stac.top()=='('){
                if(st[i]==')') stac.pop();
                else if(st[i]==']'){
                    det++;
                    break;
                }
                continue;
            }
        }
        if(stac.empty() && det==0) cout<<"yes"<<'\n';
        else cout<<"no"<<'\n';
    }
}