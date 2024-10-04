#include<iostream>
using namespace std;
int main(){//1904
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,t;
    cin>>N;
    int tile[N];
    tile[0]=1;
    tile[1]=2;
    tile[2]=3;
    tile[3]=5;
    for(int i=4; i<N; ++i){
        tile[i]=((tile[i-1]%15746)+(tile[i-2]%15746))%15746;
    }
    cout<<tile[N-1]<<'\n';
}