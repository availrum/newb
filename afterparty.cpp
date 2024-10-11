#include<iostream>
using namespace std;
int main(){//2845
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int L,P,t;
    cin>>L>>P;
    int sum=L*P;
    for(int i=0; i<5; ++i){
        cin>>t;
        cout<<t-sum;
        if(i!=5) cout<<' ';
    }
    cout<<'\n';
}