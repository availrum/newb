#include<iostream>
using namespace std;
int main(){ //5343
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    for(int i=0; i<N; ++i){
        string st;
        cin>>st;
        int none=0, idx=0;
        while(idx<st.length()){
            int cnt=0;
            for(int j=idx; j<idx+7; ++j){
                if(st[j]-'0'==1){
                    ++cnt;
                }
            }
            cnt%=2;
            if((int)(st[idx+7]-'0')!=cnt){
                ++none;
            }
            idx+=8;
        }
        cout<<none<<'\n';
    }
}