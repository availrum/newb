#include<iostream>
#include<vector>
using namespace std;
int main(){ //2960
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,K;
    cin>>N>>K;
    int cnt=0, sol=0;
    bool flag=false;
    vector<bool> prime(N+1,true);
    for(int i=2; i<=N; ++i){
        if(!prime[i]) continue;
        for(int j=1; i*j<=N; ++j){
            if(!prime[i*j]) continue;
            prime[i*j]=false;
            ++cnt;
            if(cnt==K){
                sol=i*j;
                flag=true;
                break;
            }
        }
        if(flag) break;
    }
    cout<<sol<<'\n';
}