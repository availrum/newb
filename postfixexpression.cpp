#include<iostream>
#include<stack>
using namespace std;
int main(){//1918
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string st,sol="";
    cin>>st;
    stack<char> ope;
    for(int i=0; i<=st.length(); ++i){
        if(i==st.length()){
            while(!ope.empty()){
                if(!(ope.top()=='(' || ope.top()==')')) sol+=ope.top();
                ope.pop();
            }
        }
        else if(isalpha(st[i])){
            sol+=st[i];
        }
        else{
            if(ope.empty()) ope.push(st[i]);
            else if(st[i]=='('){
                ope.push(st[i]);
            }
            else if(st[i]==')'){
                while(!ope.empty()){
                    if(ope.top()=='('){
                        ope.pop();
                        break;
                    }
                    else{
                        sol+=ope.top();
                        ope.pop();
                    }
                }
            }
            else if(ope.top()=='('){
                ope.push(st[i]);
            }
            else if (st[i]=='*' || st[i]=='/'){
                if(ope.top()=='+' || ope.top()=='-') ope.push(st[i]);
                else if(ope.top()=='*' || ope.top()=='/'){
                    while(!ope.empty() && (ope.top()=='*' || ope.top()=='/')){
                        if(ope.top()=='(') break;
                        sol+=ope.top();
                        ope.pop();
                    }
                    ope.push(st[i]);
                }
            }
            else if(st[i]=='+' || st[i]=='-'){
                while(!ope.empty() && !(ope.top()=='(' || ope.top()==')')){
                    sol+=ope.top();
                    ope.pop();
                }
                ope.push(st[i]);
            }
        }
    }
    cout<<sol<<'\n';
}