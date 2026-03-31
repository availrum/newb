#include<iostream>
#include<stack>
#include<unordered_map>
#define ll long long int
using namespace std;
int main(){ //3015
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N,t;
    cin>>N;
    ll cnt=0;
    stack<ll> st;
    // cout<<'\n';
    unordered_map<ll,ll> num;
    //24 41 12 42 22 42 25 25 45 51
    // 41 42 22 42 51
    for(int i=0; i<N; ++i){
        cin>>t;
        if(!st.empty()){
            if(st.top()<t){
                while(!st.empty() && st.top()<t){
                    // cout<<st.top()<<' '<<t<<'\n';
                    cnt+=num[st.top()];
                    num[st.top()]=0;
                    st.pop();
                }
                if(!st.empty()){
                    if(st.top()==t){
                        if(st.size()>1) cnt+=(num[t]+1);
                        else cnt+=num[t];
                        ++num[t];
                        continue;
                    }
                    else ++cnt;

                }
            }
            else if(st.top()==t){
                if(st.size()>1) cnt+=(num[t]+1);
                else cnt+=num[t];
                ++num[t];
                continue;
            }
            else{
                // cout<<st.top()<<' '<<t<<' '<<num[t]<<'\n';
                ++cnt;
            }
        }
        st.push(t);
        ++num[t];
    }
    // cout<<'\n'<<st.size()<<'\n';
    cout<<cnt<<'\n';
}