#include<iostream>
using namespace std;
void kmp(int* stat, string arr, int n){
    int i=-1, j=0;
    stat[j]=i;
    while(j<n){
        if(i==-1 || arr[i]==arr[j]){
            ++i, ++j;
            stat[j]=i;
        }
        else{
            i=stat[i];
        }
    }
}
int main(){//14959
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string st;
    cin>>st;
    int stat[st.length()+1];
    kmp(stat,st,st.length());
    int ptl=st.length()-stat[st.length()];
    // for(int i=0; i<=st.length(); ++i) cout<<stat[i]<<' ';
    // cout<<'\n';
    cout<<st.length()/ptl<<'\n';
}