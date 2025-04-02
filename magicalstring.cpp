#include<iostream>
#include<algorithm>
using namespace std;
int cnt, K;
void kmp(int* stat, string pattern){
    int N=pattern.length();
    int i=-1, j=0;
    stat[j]=i;
    while(j<N){
        if(i==-1 || pattern[i]==pattern[j]){
            ++i, ++j;
            stat[j]=i;
        }
        else{
            i=stat[i];
        }
    }
}
void find_pattern(string origin, string pattern){
    int L=pattern.length();
    int stat[L+1]={0,};
    kmp(stat,pattern);
    int i=0, j=0;
    int num=0;
    while(i<2*L-1){
        if(j==-1 || origin[i]==pattern[j]){
            ++i, ++j;
        }
        else j=stat[j];

        if(j==L){
            ++num;
            j=stat[j];
        }
    }
    if(num==K) ++cnt;
}
int main(){//1097
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    pair<string,int> st[N];
    string  tmp;
    for(int i=0; i<N; ++i){
        cin>>tmp;
        st[i].first=tmp;
        st[i].second=i;
    }
    cin>>K;
    string str="", pattern="";
    sort(st,st+N);
    for(int i=0; i<N; ++i){
        // str=pattern+st[i];
        pattern+=st[i].first;
        // str+=pattern;
        // find_pattern(str,pattern);
    }
    str=pattern+pattern;
    find_pattern(str,pattern);
    while(next_permutation(st,st+N)){
        str="", pattern="";
        for(int i=0; i<N; ++i){
            // str=pattern+st[i];
            pattern+=st[i].first;
            // str+=pattern;
            // find_pattern(str,pattern);
        }
        str=pattern+pattern;
        // str+=pattern;
        find_pattern(str,pattern);
    }
    cout<<cnt<<'\n';
}