#include<iostream>
using namespace std;
int main(){//11005
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string N;
    char kk;
    long long int B,sol=0,tmp=1,idx=0;
    cin>>N>>B;
    long long int intn=stoi(N);
    while(intn>=tmp) tmp*=B;
    tmp/=B;
    if(tmp==0) tmp=1;
    while(tmp>0){
        // cout<<intn<<' '<<tmp<<' '<<intn/tmp<<'\n';
        if(intn/tmp>=10){
            kk=intn/tmp+55;
            cout<<kk;
        }
        else cout<<intn/tmp;
        intn%=tmp;
        tmp/=B;
    }
    cout<<'\n';
}