#include<iostream>
using namespace std;
int main(){//2745
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string N;
    int B,sol=0,tmp=1;
    cin>>N>>B;
    for(int i=N.length()-1; i>=0; --i){
        if(N[i]<58) sol+=(N[i]-48)*tmp;
        else sol+=(N[i]-55)*tmp;
        tmp*=B;
    }
    cout<<sol<<'\n';
}