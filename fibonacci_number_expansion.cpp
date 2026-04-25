#include<iostream>
#include<vector>
using namespace std;
const int divid=1000000000;
int main(){ //1788
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,t;
    cin>>N;
    int absn=abs(N);
    vector<int> num(2*absn+1, -1);
    num[absn]=0;
    num[absn+1]=1;
    int sol;
    for(int i=absn+2; i<=2*absn; ++i){
        num[i]=(num[i-1]+num[i-2])%divid;
    }
    for(int i=absn-1; i>=0; --i){
        num[i]=(num[i+2]-num[i+1])%divid;
    }
    if(N>=0) sol=num[2*N];
    else sol=num[0];
    
    if(sol>0) cout<<"1\n";
    else if(sol==0) cout<<"0\n";
    else cout<<"-1\n";
    cout<<abs(sol)<<'\n';
}