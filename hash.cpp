#include<iostream>
#include<cmath>
using namespace std;
int main(){//15829
    int L, r=31;
    long long int sol=0,tmp,tmpr=1;
    long long int M=1234567891;
    char a;
    cin>>L;
    for(int i=0;i<L; i++){
        cin>>a;
        tmp=(int(a)-96)*tmpr;
        sol=(sol%M+tmp%M)%M;
        tmpr=(tmpr%M*(r))%M;
    }
    cout<<sol<<'\n';
    return 0;
}