#include<iostream>
#define ll long long int
using namespace std;
ll comb(ll a, ll b){//10_C_3, 
    ll tmp=1;
    if(b==2) tmp=a*(a-1)/2;
    else if(b==3) tmp=a*(a-1)*(a-2)/6;
    return tmp;
}
int main(){ //26084
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll handle[3]={0,};
    string S;
    cin>>S;
    int N;
    cin>>N;
    for(int i=0; i<N; ++i){
        string t;
        cin>>t;
        if(t[0]==S[0]) ++handle[0];
        if(t[0]==S[1]) ++handle[1];
        if(t[0]==S[2]) ++handle[2];
    }
    ll sol;
    if(S[0]==S[1]){
        if(S[1]==S[2]) sol=comb(handle[0],3);
        else sol=comb(handle[0],2)*handle[2];
    }
    else if(S[0]==S[2]) sol=comb(handle[0],2)*handle[1];
    else if(S[1]==S[2]) sol=comb(handle[1],2)*handle[0];
    else sol=handle[0]*handle[1]*handle[2];
    cout<<sol<<'\n';
}