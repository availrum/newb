#include<iostream>
using namespace std;
int main(){//24265
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long int n,num;
    cin>>n;
    if(n%2==1) num=n*(n/2);
    else num=(n-1)*(n/2);
    cout<<num<<'\n';
    cout<<"2"<<'\n';
}