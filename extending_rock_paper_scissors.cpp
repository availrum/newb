#include<iostream>
using namespace std;
int main(){ //16104
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int lota=(N-1)/2;
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=lota; ++j){
            int loser=(i+j-1)%N+1;
            cout<<i<<' '<<loser<<'\n';
        }
    }
}