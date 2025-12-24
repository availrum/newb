#include<iostream>
#include<vector>
using namespace std;
int main(){ //6588
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    const int con=1000001;
    vector<bool> prime(con,true);
    for(int i=2; i*i<con; ++i){
        if(!prime[i]) continue;
        for(int j=2; i*j<con; ++j){
            prime[i*j]=false;
        }
    }
    vector<int> list_prime;
    for(int i=3; i<con; ++i){
        if(prime[i]) list_prime.push_back(i);
    }
    // 100만아래 소수 78497~=10만, 테케1000개 ~= 연산 1억번 ... 1초근처
    // N/2까지 소수만 본다하면 대략 0.5초
    while(cin>>N){
        if(N==0) break;
        int a=-1, b=-1;
        for(int i=0; i<list_prime.size(); ++i){
            if(list_prime[i]>(N/2)) break;
            if(prime[N-list_prime[i]]){
                a=list_prime[i];
                b=N-list_prime[i];
                break;
            }
        }
        if(a==-1) cout<<"Goldbach's conjecture is wrong.\n";
        else cout<<N<<" = "<<a<<" + "<<b<<'\n';
    }
    // cout<<list_prime.size()<<'\n';
}