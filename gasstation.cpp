#include<iostream>
using namespace std;
int main(){//13305
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int N,t;
    cin>>N;
    long long int distance[N-1]={0,};
    for(int i=0; i<N-1; ++i){
        cin>>distance[i];
    }
    int station[N];
    for(int i=0; i<N; ++i){
        cin>>station[i];
    }
    long long int tmp=station[0], tmpidx=0, cost=0;
    long long int dist=0;

    for(int i=0; i<N; ++i){
        if(tmp>station[i] || i==N-1){
            cost+=dist*station[tmpidx];
            cout<<dist<<' '<<cost<<' '<<station[tmpidx]<<'\n';
            tmp=station[i];
            tmpidx=i;
            dist=0;
        }
        dist+=distance[i];
    }
    cout<<cost<<'\n';
}