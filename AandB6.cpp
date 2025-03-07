#include<iostream>
using namespace std;
int main(){//10953
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tcase;
    cin>>tcase;
    int a,b;
    string st;
    for(int i=0; i<tcase; ++i){
        cin>>st;
        int sum=(st[0]-'0')+(st[2]-'0');
        cout<<sum<<'\n';
    }
}