#include<iostream>
#include<vector>
using namespace std;
int main(){ //1652
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    vector<vector<int>> room(N,vector<int>(N,0));
    string st;
    for(int i=0; i<N; ++i){
        cin>>st;
        for(int j=0; j<st.length(); ++j){
            if(st[j]=='X') room[i][j]=1;
        }
    }
    int cnt1=0, cnt2=0;
    for(int i=0; i<N; ++i){
        int tmp=0;
        for(int j=0; j<N; ++j){
            if(room[i][j]==0) ++tmp;
            else{
                if(tmp>1) ++cnt1;
                tmp=0;
            }
        }
        if(tmp>1) ++cnt1;
    }
    for(int j=0; j<N; ++j){
        int tmp=0;
        for(int i=0; i<N; ++i){
            if(room[i][j]==0) ++tmp;
            else{
                if(tmp>1) ++cnt2;
                tmp=0;
            }
        }
        if(tmp>1) ++cnt2;
    }
    cout<<cnt1<<' '<<cnt2<<'\n';
}