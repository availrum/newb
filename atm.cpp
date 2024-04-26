#include<iostream>
#include<algorithm>
using namespace std;
int main(){//11399
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,sum=0;
    cin>>N;
    int P[N+1],PS[N+1];
    for(int i=0; i<N; i++){
        cin>>P[i];
    }
    sort(P,P+N);
    PS[0]=P[0];
    sum+=P[0];
    for(int i=1; i<N; i++){//1 3  6 
        PS[i]=P[i]+PS[i-1];
        sum+=PS[i];
    }
    cout<<sum<<'\n';
    return 0;
}
