#include<iostream>
#include<vector>
#define ll long long int
using namespace std;
int main(){ //2688
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int tcase=0; tcase<T; ++tcase){
        ll N,t;
        cin>>N;
        vector<vector<ll>> arr(N+1,vector<ll>(10,0));
        for(int i=0; i<=N; ++i){
            for(int j=0; j<10; ++j){
                if(i==0){
                    arr[i][j]=1;
                    break;
                }
                for(int k=j; k>=0; --k){
                    arr[i][j]+=arr[i-1][k];
                }
            }
        }
        ll sol=0;
        for(int i=0; i<10; ++i) sol+=arr[N][i];
        cout<<sol<<'\n';
    }
}