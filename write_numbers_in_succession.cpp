#include<iostream>
using namespace std;
int main(){ //1748
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int num=1, cnt=0, val=1;
    while(num<=N){
        if(num*10<=N) cnt+=(9*num)*val;
        else cnt+=(N-num+1)*val;
        num*=10;
        ++val;
    }
    cout<<cnt<<'\n';
}