#include<iostream>
using namespace std;
int chec(int a, int b){
    return a<b ? a:b;
}
int main(){//11047
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,K,tmp,cnt=0,num=0;
    cin>>N>>K;
    int A[N+1];
    for(int i=0; i<N; i++){
        cin>>A[i];
    }
    for(int i=N-1; i>=0; i--){
        if(A[i]>K) continue;
        tmp=K;
        cnt=0;
        if(tmp-A[i]==0) {
            cout<<"1"<<'\n';
            return 0;
        }
        for(int j=i; j>=0; j--){
            if(tmp<A[j]) continue;
            cnt+=tmp/A[j];
            tmp-=A[j]*(tmp/A[j]);
            if(tmp==0){
                if(num==0 || num>cnt) num=cnt;
                break;
            }
        }
    }
    cout<<num<<'\n';
}