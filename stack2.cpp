#include<iostream>
#include<stack>
using namespace std;
int main(){//28278
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,b;
    string a;
    stack<int> st;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>a;
        if(a=="1"){
            cin>>b;
            st.push(b);
        }
        if(a=="2"){
            if(st.empty()==1){
                cout<<"-1"<<'\n';
                continue;
            }
            cout<<st.top()<<'\n';
            st.pop();
        }
        if(a=="3"){
            cout<<st.size()<<'\n';
        }
        if(a=="4"){
            cout<<int(st.empty())<<'\n';
        }
        if(a=="5"){
            if(st.empty()==1){
                cout<<"-1"<<'\n';
                continue;
            }
            cout<<st.top()<<'\n';
        }
    }

    return 0;
}