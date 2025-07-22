#include<iostream>
#include<algorithm>
using namespace std;
int main(){ //6159
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int S,N;
    cin>>N>>S;
    int cow[N];
    for(int i=0; i<N; ++i){
        cin>>cow[i];
    }
    sort(cow,cow+N);
    int cnt=0;
    for(int i=0; i<N-1; ++i){
        if(cow[i]+cow[i+1]>S) break;
        for(int j=i+1; j<N; ++j){
            if(cow[i]+cow[j]<=S) ++cnt;
            else break;
        }
    }
    cout<<cnt<<'\n';
}