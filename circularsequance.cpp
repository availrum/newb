#include<iostream>
using namespace std;
int sol;
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
void find_pattern(string arr, string pattern){
    int n=arr.length();
    int m=pattern.length();
    int stat[m+1];
    kmp(stat,pattern);
    int i=0, j=0;
    while(i<n){
        if(j==-1 || arr[i]==pattern[j]){
            ++i, ++j;
        }
        else j=stat[j];

        if(j==m){
            ++sol;
            j=stat[j];
        }
    }
}
int main(){//12104
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string A, st, pattern;
    cin>>A;
    cin>>pattern;
    st=A;
    for(int i=0; i<A.length()-1; ++i){
        st+=A[i];
    }
    find_pattern(st,pattern);
    cout<<sol<<'\n';
}