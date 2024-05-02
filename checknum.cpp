#include<iostream>
using namespace std;
int main(){//2475
    int N,sol=0;
    for(int i=0; i<5; i++){
        cin>>N;
        sol+=N*N;
    }
    sol=sol%10;
    cout<<sol<<'\n';
    return 0;
}