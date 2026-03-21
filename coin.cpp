#include<iostream>
#include<vector>
using namespace std;
int main(){ //9084
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int tcase=0; tcase<T; ++tcase){
        int N;
        cin>>N;
        vector<int> coin(N,0);
        for(int i=0; i<N; ++i){
            cin>>coin[i];
        }
        int M;
        cin>>M;
        vector<int> cnt(M+1,0);
        cnt[0]=1;
        for(int i=0; i<N; ++i){
            for(int val=0; val<coin[i]; ++val){
                for(int j=1; val+coin[i]*j<=M; ++j){
                    cnt[val+j*coin[i]]+=cnt[val+(j-1)*coin[i]];
                }
            }
        }
        //1111111111 111111112 11111122 1111222 112222 22222
        // for(int i=0; i<=M; ++i) cout<<cnt[i]<<' ';
        // cout<<'\n';
        // cout<<'\n'<<
        cout<<cnt[M]<<'\n';
    }
}