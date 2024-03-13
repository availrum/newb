#include<iostream>
#include<map>
#include<stack>
using namespace std;
int main(){
    int N,b;
    string a;
    stack<int> st;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>a;
        if(a=="push"){
            cin>>b;
            st.push(b);
        }
        if(a=="pop"){
            if(st.empty()==1){
                cout<<"-1"<<'\n';
                continue;
            }
            cout<<st.top()<<'\n';
            st.pop();
        }
        if(a=="size"){
            cout<<st.size()<<'\n';
        }
        if(a=="empty"){
            cout<<int(st.empty())<<'\n';
        }
        if(a=="top"){
            if(st.empty()==1){
                cout<<"-1"<<'\n';
                continue;
            }
            cout<<st.top()<<'\n';
        }
    }

    return 0;
}