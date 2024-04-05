#include<iostream>
#include<stack>
using namespace std;
int main(){//10773
    int K, n;
    long long int sol=0;
    stack<int> st;
    cin>>K;
    for(int i=0; i<K; i++){
        cin>>n;
        if(!n){
            st.pop();
            continue;
        }
        st.push(n);
    }
    for(int i=0; st.size(); i++){
        sol+=st.top();
        st.pop();
    }
    cout<<sol<<'\n';
}