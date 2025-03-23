#include<iostream>
#include<vector>
using namespace std;
vector<int> sol;
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
            // cout<<i-m+1<<'\n';
            sol.push_back(i-m+1);
            j=stat[j];
        }
    }
}
int main(){//1786
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string st, pattern;
    getline(cin,st);
    // cin>>pattern;
    getline(cin,pattern);
    if(st.length()<pattern.length()){
        cout<<"0"<<'\n';
        return 0;
    }
    find_pattern(st,pattern);
    // cout<<st<<'\n';
    cout<<sol.size()<<'\n';
    for(int i=0; i<sol.size(); ++i){
        cout<<sol[i];
        if(i!=sol.size()-1) cout<<' ';
        else cout<<'\n';
    }
}