#include<iostream>
using namespace std;

int bonac(int n){
    // int n;
    if(n==0) return 0; 
    else if(n==1) return 1;
    else
    n=bonac(n-1)+bonac(n-2);
    return n;
} 
int main(){
    int N;
    cin>>N;
    cout<<bonac(N)<<'\n';
    return 0;
}