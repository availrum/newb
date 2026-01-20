#include<iostream>
#include<algorithm>
using namespace std;
int main(){ //1449
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,L;
    cin>>N>>L;
    int pipe[N];
    for(int i=0; i<N; ++i){
        cin>>pipe[i];
    }
    sort(pipe,pipe+N);
    int st=pipe[0]-1, ed=pipe[0]-1+L, idx=1, cnt=1;
    while(idx<N){
        if(pipe[idx]>st && pipe[idx]<=ed){
            ++idx;
        }
        else{
            st=pipe[idx]-1;
            ed=pipe[idx]-1+L;
            ++cnt;
            ++idx;
        }
    }
    cout<<cnt<<'\n';
}