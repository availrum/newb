#include<iostream>
using namespace std;
int K;
int cal(long long int a, long long int b){
    int distance=0;
    while(a!=b){
        ++distance;
        if(a<b) swap(a,b);
        a=(a-2)/K+1;
    }
    return distance;
}
int main(){//11812
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int N;
    int Q;
    cin>>N>>K>>Q;
    long long int x,y;
    for(int i=0; i<Q; ++i){
        cin>>x>>y;
        if(K==1){
            cout<<abs(x-y)<<'\n';
        }
        else{
            int sol = cal(x,y);
            cout<<sol<<'\n';
        }
    }
}