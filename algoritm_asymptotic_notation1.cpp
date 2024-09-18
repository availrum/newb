#include<iostream>
using namespace std;
int main(){//24313
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int a1,a0,c,n0;
    cin>>a1>>a0;
    cin>>c;
    cin>>n0;
    if(a1>c){
        if(2147483646 + a0/(a1-c)<=0) cout<<"1"<<'\n';
        else cout<<"0"<<'\n';
    }
    else if(a1<c){
        if(n0+a0/(a1-c)>=0) cout<<"1"<<'\n';
        else cout<<"0"<<'\n';
    }
    else{
        if(a0<=0) cout<<"1"<<'\n';
        else cout<<"0"<<'\n';
    }
}