#include<iostream>
using namespace std;
void kmp(int* stat, string pattern, int idx){
    int n = pattern.length();
    int i=-1, j=idx;
    stat[j]=i;
    while(j<n){
        if(i==-1 || pattern[i+idx]==pattern[j]){
            ++i, ++j;
            stat[j]=i;
        }
        else{
            i=stat[i+idx];
        }
    }
}
int main(){//1701
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string st;
    cin>>st;
    int sol=0;
    for(int j=0; j<st.length(); ++j){
        int pattern[st.length()+1]={0,};
        kmp(pattern,st,j);
        for(int i=j+1; i<=st.length(); ++i){
            sol=max(pattern[i],sol);
            // cout<<pattern[i];
        }
    }
    cout<<sol<<'\n';
}