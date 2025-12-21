#include<iostream>
using namespace std;
int main(){ //14916
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int cnt=0;
    if(n<5 && n%2!=0) cnt=-1;
    else if(n%5==0) cnt=n/5;
    else{
        cnt=n/5;
        n%=5;
        if(n%2==0) cnt+=n/2;
        else{
            --cnt;
            n+=5;
            cnt+=n/2;
        }
    } 
    cout<<cnt<<'\n';
}