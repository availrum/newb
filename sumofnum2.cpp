#include<iostream>
#define ll long long int
using namespace std;
int main(){//2003
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N, M;
    cin>>N>>M;
    ll A[N], tmp;
    ll cnt=0;
    for(int i=0; i<N; ++i){
        cin>>tmp;
        if(i!=0) A[i]=A[i-1]+tmp;
        else A[i]=tmp;
        if(A[i]==M) ++cnt;
    }

    if(N==1){
        cout<<cnt<<'\n';
        return 0;
    }

    int st=0, ed=0;
    while(st<N){

        if(A[ed]-A[st]<M){
            ++ed;
            if(ed>=N) break;
        }
        else if(A[ed]-A[st]>M){
            ++st;
        }
        else{
            ++st;
            ++ed;
            ++cnt;
            if(ed>=N) break;
        }
    }
    cout<<cnt<<'\n';
}
