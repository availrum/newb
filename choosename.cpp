#include<iostream>
using namespace std;
void kmp(long long int* stat, string pattern){
    long long int n = pattern.length();
    long long int i=-1, j=0;
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
int main(){//16900
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string st;
    cin>>st;
    long long int n;
    cin>>n;
    long long int pattern[st.length()+1]={0,};
    kmp(pattern,st);
    long long int patternlen=st.length()-pattern[st.length()];
    long long int sol=st.length()+(n-1)*patternlen;
    cout<<sol<<'\n';
}