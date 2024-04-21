#include<iostream>
#include<map>
#include<deque>
using namespace std;
int main(){//28279
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,b;
    string a;
    deque<int> st;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>a;
        if(a=="1"){
            cin>>b;
            st.push_front(b);
        }
        if(a=="2"){
            cin>>b;
            st.push_back(b);
        }
        if(a=="3"){
            if(st.empty()==1){
                cout<<"-1"<<'\n';
                continue;
            }
            cout<<st.front()<<'\n';
            st.pop_front();
        }
        if(a=="4"){
            if(st.empty()==1){
                cout<<"-1"<<'\n';
                continue;
            }
            cout<<st.back()<<'\n';
            st.pop_back();
        }
        if(a=="5"){
            cout<<st.size()<<'\n';
        }
        if(a=="6"){
            cout<<int(st.empty())<<'\n';
        }
        if(a=="7"){
            if(st.empty()==1){
                cout<<"-1"<<'\n';
                continue;
            }
            cout<<st.front()<<'\n';
        }
        if(a=="8"){
            if(st.empty()==1){
                cout<<"-1"<<'\n';
                continue;
            }
            cout<<st.back()<<'\n';
        }
    }

    return 0;
}