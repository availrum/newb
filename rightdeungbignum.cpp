#include<iostream>
#include<stack>
#include<unordered_map>
using namespace std;
int main(){//17299
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int arr[N];
    stack<int> st;
    unordered_map<int,int> check;
    for(int i=0; i<N; ++i){
        cin>>arr[i];
        st.push(arr[i]);
        ++check[arr[i]];
    }
    stack<int> rbn, sol;
    for(int i=0; i<N; ++i){
        if(rbn.empty()){
            sol.push(-1);
            rbn.push(st.top());
            st.pop();
        }
        else{
            while(!rbn.empty()){
                if(check[rbn.top()]<=check[st.top()]){
                    rbn.pop();
                }
                else if(check[rbn.top()]>check[st.top()]){
                    break;
                }
            }
            if(rbn.empty()){
                sol.push(-1);
                rbn.push(st.top());
                st.pop();
            }
            else{
                sol.push(rbn.top());
                rbn.push(st.top());
                st.pop();
            }
        }
    }
    while(!sol.empty()){
        cout<<sol.top();
        sol.pop();
        if(!sol.empty()) cout<<' ';
        else cout<<'\n';
    }
}