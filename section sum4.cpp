#include<iostream>
using namespace std;
int main(){//11659
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M,sol=0,tmp=0;
    cin>>N>>M;
    int ar[N+1],sum[M+1];
    
    for(int i=0; i<N; i++){
        cin>>ar[i];
        tmp+=ar[i];
        sum[i]=tmp;
    }
    for(int k=0; k<M; k++){
        int i,j;
        cin>>i>>j;
        if(i==1){
            cout<<sum[j-1]<<'\n';
            continue;
        }
        cout<<sum[j-1]-sum[i-2]<<'\n';
    }
    return 0;
}
