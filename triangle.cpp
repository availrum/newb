#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int N,a[3];
    while(cin>>a[0]>>a[1]>>a[2]){
        if((a[0]==a[1] && a[1]==0) && a[2]==0) return 0;
        sort(a,a+3);
        if((a[0]*a[0]+a[1]*a[1])==a[2]*a[2]) cout<<"right"<<'\n';
        else cout<<"wrong"<<'\n';
    }
}