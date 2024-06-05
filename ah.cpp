#include<iostream>
using namespace std;
int main(){//4999
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    string st1,st2;
    cin>>st1>>st2;
    int a=0;
    for(int i=0; i<st1.length(); ++i){
        if(st1[i]=='a') a++;
    }
    if(a>=st2.length()-1) cout<<"go"<<'\n';
    else cout<<"no"<<'\n';
}