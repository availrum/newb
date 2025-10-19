#include<iostream>
#include<stack>
using namespace std;
int main(){ //10799
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str; // 50000*50000 -> 2,500,000,000 / (())-> 2, ( ( ( () ) ) )->6
    cin>>str;
    stack<int> st;
    int iron=0, cnt=0;
    for(int i=0; i<str.length(); ++i){
        if(str[i]=='('){
            ++iron;
            st.push(iron);
        }
        else if(str[i]==')'){
            --iron;
            if(str[i-1]=='('){
                st.pop();
                cnt+=iron;
            }
            else ++cnt;
        }
    }
    cout<<cnt<<'\n';
}