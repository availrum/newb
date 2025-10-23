#include<iostream>
#include<vector>
using namespace std;
bool no_prime[10001];
int main(){ //9020
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=2; i<=100; ++i){
        for(int j=2; i*j<=10000; ++j){
            no_prime[i*j]=true;
        }
    }
    int T;
    cin>>T;
    for(int tcase=0; tcase<T; ++tcase){
        int N;
        cin>>N;
        vector<int> prime;
        for(int i=2; i<N; ++i){
            if(!no_prime[i]) prime.push_back(i);
        }
        pair<int,int> gp={0,N+1};
        for(int i=0; i<prime.size(); ++i){
            if(!no_prime[N-prime[i]]){
                if(abs(N-2*prime[i])<abs(gp.second-gp.first)){
                    gp.first=prime[i];
                    gp.second=N-prime[i];
                }
            }
        }
        cout<<gp.first<<' '<<gp.second<<'\n';
    }
}