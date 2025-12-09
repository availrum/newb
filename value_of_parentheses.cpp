#include<iostream>
#include<stack>
#include<vector>
#include<queue>
using namespace std;
int main(){ //2504
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;
    cin>>str;
    int num=1, tmp=0, depth=0;
    stack<char> st;
    queue<int> qu;
    vector<int> value(1,1);
    for(int i=0; i<str.length(); ++i){
        // cout<<value.size()<<'\n';
        if(str[i]==')'){
            if(st.empty() || st.top()!='('){
                cout<<"0\n";
                return 0;
            }
            else{
                st.pop();
                if(value[value.size()-2]!=1) value[value.size()-2]+=value[value.size()-1]*2;
                else value[value.size()-2]=value[value.size()-1]*2;
                value.pop_back();
            }
        }
        else if(str[i]=='('){
            st.push(str[i]);
            value.push_back(1);
        }
        else if(str[i]==']'){
            if(st.empty() || st.top()!='['){
                cout<<"0\n";
                return 0;
            }
            else{
                st.pop();
                if(value[value.size()-2]!=1) value[value.size()-2]+=value[value.size()-1]*3;
                else value[value.size()-2]=value[value.size()-1]*3;
                value.pop_back();
            }
        }
        else if(str[i]=='['){
            st.push(str[i]);
            value.push_back(1);
        }
    }
    if(st.empty()) cout<<value[0]<<'\n';
    else cout<<"0\n";
}