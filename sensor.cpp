#include<iostream>
#include<algorithm>
using namespace std;
int main(){//2212
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,K;
    cin>>N>>K;
    int sensor[N];
    for(int i=0; i<N; ++i){
        cin>>sensor[i];
    }
    sort(sensor,sensor+N);
    int diff[N]={2147483647,};
    for(int i=1; i<N; ++i){
        diff[i]=sensor[i]-sensor[i-1];
    }
    sort(diff,diff+N);
    int tot=0;
    for(int i=0; i<N-K; ++i){
        tot+=diff[i];
    }
    cout<<tot<<'\n';

}