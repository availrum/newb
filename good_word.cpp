#include<iostream>
#include<stack>
using namespace std;
int main(){ //3986
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int cnt=0;
    for(int i=0; i<N; ++i){
        string str;
        cin>>str;
        stack<char> st;
        for(int j=0; j<str.length(); ++j){
            if(st.empty()) st.push(str[j]);
            else if(str[j]==st.top()) st.pop();
            else st.push(str[j]);
        }
        if(st.empty()) ++cnt;
    }
    cout<<cnt<<'\n';
}