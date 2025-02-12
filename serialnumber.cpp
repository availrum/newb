#include<iostream>
#include<algorithm>
using namespace std;
bool sor(string st1, string st2){
    if(st1.length() != st2.length()){
        return st1.length() <= st2.length();
    }
    else{
        int sum1=0, sum2=0;
        for(int i=0; i<st1.length(); ++i){
            if(isdigit(st1[i])){
                sum1+=(st1[i]-'0');
            }
        }
        for(int i=0; i<st2.length(); ++i){
            if(isdigit(st2[i])){
                sum2+=(st2[i]-'0');
            }
        }
        if(sum1!=sum2) return sum1<=sum2;
        else return st1<=st2;
    }
}
int main(){//1431
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    string st[N];
    for(int i=0; i<N; ++i){
        cin>>st[i];
    }
    sort(st,st+N,sor);
    // cout<<'\n';
    for(int i=0; i<N; ++i){
        cout<<st[i]<<'\n';
        // if(i!=N-1) cout<<' ';
        // else cout<<'\n';
    }
}