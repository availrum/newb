#include<iostream>
#include<unordered_map>
using namespace std;
int main(){ //4158
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    while(cin>>N>>M){
        if(N==0 && M==0) break;
        unordered_map<int,int> check;
        int cnt=0, tmp;
        for(int i=0; i<N; ++i){
            cin>>tmp;
            ++check[tmp];
        }
        for(int i=0; i<M; ++i){
            cin>>tmp;
            if(check[tmp]) ++cnt;
        }
        cout<<cnt<<'\n';
    }
}