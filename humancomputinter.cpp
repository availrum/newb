#include<iostream>
using namespace std;
int main(){//16139
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string st;
    cin>>st;
    int tot[26][st.length()];
    for(int i=0; i<26; ++i) for(int j=0; j<st.length(); ++j) tot[i][j]=0;
    int sum=0;
    for(int i=0; i<st.length(); ++i){
        for(int j=0; j<26; ++j) if(i!=0) tot[j][i]=tot[j][i-1];
        ++tot[st[i]-'a'][i];
    }
    int q;
    cin>>q;
    char alpha;
    int start,end;
    for(int i=0; i<q; ++i){
        cin>>alpha>>start>>end;
        if(start-1>=0) cout<<tot[alpha-'a'][end]-tot[alpha-'a'][start-1]<<'\n';
        else cout<<tot[alpha-'a'][end]<<'\n';
    }
}