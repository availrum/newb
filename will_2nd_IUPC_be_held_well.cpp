#include<iostream>
#include<algorithm>
using namespace std;
int main(){ //12788
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M,K;
    cin>>N>>M>>K;
    int CTP[N];
    int need_pen=M*K;
    for(int i=0; i<N; ++i){
        cin>>CTP[i];
    }
    sort(CTP,CTP+N);
    int pen=0, cnt=0;
    for(int i=N-1; i>=0; --i){
        pen+=CTP[i];
        ++cnt;
        if(need_pen<=pen) break;
    }
    if(need_pen<=pen) cout<<cnt<<'\n';
    else cout<<"STRESS"<<'\n';
}