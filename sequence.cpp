#include<iostream>
using namespace std;
int main(){//2559
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,K;
    cin>>N>>K;
    int seq[N],sum=0;
    for(int i=0; i<N; ++i){
        cin>>seq[i];
        if(i<K) sum+=seq[i];
    }
    int st=0, ed=K, maxi=sum;
    while(ed<N){
        sum-=seq[st];
        sum+=seq[ed];
        if(sum>maxi) maxi=sum;
        ++st;
        ++ed;
    }
    cout<<maxi<<'\n';
}