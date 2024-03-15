#include<iostream>
#include<map>
#include<deque>
using namespace std;
int main(){
    int N,b;
    string a;
    deque<int> st;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>a;
        if(a=="push_front"){
            cin>>b;
            st.push_front(b);
        }
        if(a=="push_back"){
            cin>>b;
            st.push_back(b);
        }
        if(a=="pop_front"){
            if(st.empty()==1){
                cout<<"-1"<<'\n';
                continue;
            }
            cout<<st.front()<<'\n';
            st.pop_front();
        }
        if(a=="pop_back"){
            if(st.empty()==1){
                cout<<"-1"<<'\n';
                continue;
            }
            cout<<st.back()<<'\n';
            st.pop_back();
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