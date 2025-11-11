#include<iostream>
using namespace std;
void btr(int* channel, bool* broken_button, int max_value, string& st){
    if(st.length()>to_string(max_value).length()+1) return;
    if(st!="" && stoi(st)>max_value) return;
    int stleng=st.length();
    if(st!="") channel[stoi(st)]=min(channel[stoi(st)], stleng);
    for(int i=0; i<10; ++i){
        if(!broken_button[i]){
            st.push_back(i+'0');
            // cout<<st<<'\n';
            btr(channel, broken_button, max_value, st);
            st.pop_back();
        }
    }
}
void cal(int* channel, int max_value){
    int tmp=channel[0];
    for(int i=1; i<=max_value; ++i){
        channel[i]=min(channel[i], channel[i-1]+1);
    }
    tmp=channel[max_value];
    for(int i=max_value-1; i>=0; --i){
        channel[i]=min(channel[i], channel[i+1]+1);
    }
}
int main(){ //1107
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M,t;
    cin>>N>>M;
    bool broken_button[10]={false,};
    for(int i=0; i<M; ++i){
        cin>>t;
        broken_button[t]=true;
    }
    int max_value=max(2*N, 100);
    int channel[max_value+1];
    for(int i=0; i<=max_value; ++i){
        channel[i]=abs(100-i);
    }
    string st="";
    btr(channel, broken_button, max_value, st);
    cal(channel, max_value);
    cout<<channel[N]<<'\n';
}