#include<iostream>
#include<map>
#include<queue>
using namespace std;
int main(){
    int N,b;
    string a;
    queue<int> st;
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
            cout<<st.front()<<'\n';
            st.pop();
        }
        if(a=="size"){
            cout<<st.size()<<'\n';
        }
        if(a=="empty"){
            cout<<int(st.empty())<<'\n';
        }
        if(a=="front"){
            if(st.empty()==1){
                cout<<"-1"<<'\n';
                continue;
            }
            cout<<st.front()<<'\n';
        }
        if(a=="back"){
            if(st.empty()==1){
                cout<<"-1"<<'\n';
                continue;
            }
            cout<<st.back()<<'\n';
        }
    }

    return 0;
}