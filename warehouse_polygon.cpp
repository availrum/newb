#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){ //2304
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    vector<int> pillar(1001,0);
    for(int i=0; i<N; ++i){
        int L,H;
        cin>>L>>H;
        pillar[L]=H;
    }
    int max_value=0, max_idx=-1;
    int start=-1,end=-1;
    stack<pair<int,int>> st;
    for(int i=0; i<1001; ++i){
        if(start==-1 && pillar[i]!=0) start=i;
        if(pillar[i]!=0) end=i;
        
        if(pillar[i]==0) continue;
        else if(st.empty() || max_value<=pillar[i]){
            st.push({i,pillar[i]});
            max_value=pillar[i];
            max_idx=i;
        }
        else if(max_value>=pillar[i]){
            if(st.top().second>pillar[i]) st.push({i,pillar[i]});
            else{
                while(!st.empty() && st.top().second<=pillar[i]) st.pop();
                st.push({i,pillar[i]});
            }
        }
    }
    vector<int> arr(1001,0);
    while(!st.empty()){
        arr[st.top().first]=st.top().second;
        st.pop();
    }
    int height=0, area=arr[max_idx];
    for(int i=start; i<max_idx; ++i){
        height=max(height,arr[i]);
        area+=height;
    }
    height=0;
    // cout<<area<<'\n';
    for(int i=end; i>max_idx; --i){
        height=max(height,arr[i]);
        area+=height;
    }
    cout<<area<<'\n';
    // cout<<start<<' '<<end<<'\n';
}