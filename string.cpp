#include<iostream>
using namespace std;
int main(){//1120
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string st1,st2;
    cin>>st1>>st2;
    int mindif=st2.length();
    int maxlen=st2.length();
    for(int i=0; i<st2.length(); ++i){
        int cnt=st2.length()-st1.length();
        if(st1.length()+i > st2.length()) break;
        for(int j=0; j<st1.length(); ++j){
            if(st2[i+j]==st1[j]) ++cnt;
        }
        mindif = min(mindif, maxlen-cnt);
    }
    cout<<mindif<<'\n';
}