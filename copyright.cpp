#include<iostream>
using namespace std;
int main(){ //2914
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int A,I;
    cin>>A>>I;
    int minimum=(I-1)*A+1;
    cout<<minimum<<'\n';
}