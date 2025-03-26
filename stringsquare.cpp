#include<iostream>
using namespace std;
void kmp(int* stat, string pattern){
    int n = pattern.length();
    int i=-1, j=0;
    stat[j]=i;
    while(j<n){
        if(i==-1 || pattern[i]==pattern[j]){
            ++i, ++j;
            stat[j]=i;
        }
        else{
            i=stat[i];
        }
    }
}
int main(){//4354
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string st;
    while(getline(cin,st)){
        if(st==".") break;
        // cout<<st.length()<<'\n';
        int pattern[st.length()+1]={0,};
        kmp(pattern,st);
        // for(int i=1; i<=st.length(); ++i){
        //     cout<<pattern[i];
        //     if(i==st.length()) cout<<'\n';
        // }
        int idx=st.length();
        int patternlen=st.length()-pattern[st.length()];
        int sol;
        if(st.length()%patternlen==0) sol=st.length()/patternlen;
        else sol=1;
        // cout<<patternlen<<'\n';
        cout<<sol<<'\n';
    }
}