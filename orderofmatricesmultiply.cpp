#include<iostream>
using namespace std;
int ncal[501][501], arr[501];
int N;
int dp(int a, int b){
    if(a>=b) return 0;
    if(ncal[a][b]!=0) return ncal[a][b];
    if(a==b-1){
        ncal[a][b]=arr[a]*arr[b]*arr[b+1];
        return ncal[a][b];
    }
    int tmp=2147483647;

    for(int i=a; i<b; ++i){
        tmp=min(tmp, dp(a,i)+dp(i+1,b)+arr[a]*arr[i+1]*arr[b+1]);
    }
    ncal[a][b]=tmp;
    return tmp;
}
int main(){//11049
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    int r,c;
    for(int i=0; i<N; ++i){
        cin>>r>>c;
        arr[i]=r;
    }
    arr[N]=c;
    cout<<dp(0,N-1)<<'\n';
}