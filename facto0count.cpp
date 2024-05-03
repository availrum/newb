#include<iostream>
using namespace std;
int main(){//1676
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,cnt=0;
    cin>>N;
    //12345 - 678910 - 1112131415 - 1617181920 - 2122232425 //5의 배수가 
    cnt=N/5;
    if(N>=25) cnt+=N/25;
    if(N>=125) cnt+=N/125;
    cout<<cnt<<'\n';
}