#include<iostream>
#include<stack>
using namespace std;
int main(){ //2493
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int tower[N];
    int num[N]={0,};
    stack<pair<int,int>> st;
    for(int i=0; i<N; ++i){
        cin>>tower[i];
    }
    for(int i=N-1; i>=0; --i){
        while(!st.empty() && tower[i]>=st.top().first){
            num[st.top().second]=i+1;
            st.pop();
        }
        st.push({tower[i],i});
    }
    for(int i=0; i<N; ++i){
        cout<<num[i];
        if(i!=N-1) cout<<' ';
        else cout<<'\n';
    }
}