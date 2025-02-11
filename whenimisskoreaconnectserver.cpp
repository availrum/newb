#include<iostream>
using namespace std;
int main(){//9996
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    string pattern;
    cin>>pattern;
    string tmp="";
    string stl="", str="";
    bool patflag=false;
    for(int i=0; i<pattern.length(); ++i){
        if(pattern[i]=='*'){
            patflag=true;
            continue;
        }
        if(!patflag) stl+=pattern[i];
        else str+=pattern[i];
    }
    for(int i=0; i<N; ++i){
        string st;
        cin>>st;
        if(stl.length()+str.length()>st.length()){
            cout<<"NE"<<'\n';
            continue;
        }
        bool flag=false;
        for(int j=0; j<stl.length(); ++j){
            if(stl[j]!=st[j]){
                flag=true;
                break;
            }
        }
        for(int j=0; j<str.length(); ++j){
            if(str[str.length()-1-j]!=st[st.length()-1-j]){
                flag=true;
                break;
            }
        }
        if(!flag){
            cout<<"DA"<<'\n';
        }
        else cout<<"NE"<<'\n';
        // int dp[tmp.length()+1][st.size()+1];
        // for(int j=0; j<=tmp.length(); ++j){
        //     for(int k=0; k<=st.length(); ++k){
        //         dp[j][k]=0;
        //     }
        // }

        // for(int j=0; j<tmp.length(); ++j){
        //     for(int k=0; k<st.length(); ++k){
        //         if(tmp[j]==st[k]){
        //             dp[j+1][k+1]=dp[j][k]+1;
        //         }
        //         else dp[j+1][k+1]=max(dp[j][k+1],dp[j+1][k]);
        //     }
        // }
        // // cout<<dp[tmp.length()][st.length()]<<'\n';
        // // cout<<tmp.length()<<'\n';
        // if(dp[tmp.length()][st.length()] == tmp.length()){
        //     cout<<"DA"<<'\n';
        // }
        // else{
        //     cout<<"NE"<<'\n';
        // }
    }
}