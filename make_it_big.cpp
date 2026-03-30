#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
int main(){ //2812
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,K;
    cin>>N>>K;
    string str, sol="";
    cin>>str;
    stack<int> st;
    int cnt=K;
    for(int i=0; i<str.size(); ++i){
        int num=str[i]-'0';
        if(cnt && (!st.empty() && st.top()<num)){
            while(cnt && (!st.empty() && st.top()<num)){
                st.pop();
                --cnt;
            }
            st.push(num);
        }
        else st.push(num);
    }
    while(!st.empty()){
        if(!cnt) sol+=(st.top()+'0');
        else --cnt;
        st.pop();
    }
    reverse(sol.begin(), sol.end());
    cout<<sol<<'\n';
}