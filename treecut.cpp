#include<iostream>
#include<algorithm>
using namespace std;
int main(){//2805
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,st,ed;
    long long int M,H;
    cin>>N>>M;
    int tall[N],mid,max=0;
    for(int i=0; i<N; i++) cin>>tall[i];
    sort(tall,tall+N);

    st=1,ed=tall[N-1];
    while(st<=ed){
        H=0;
        mid=(st+ed)/2;
        for(int i=0; i<N; i++){
            if(tall[i]-mid >0) H+=(tall[i]-mid);
        }
        if(H>=M){
            st=mid+1;
            if(max<mid) max=mid;
        }
        else ed=mid-1;
    }
    cout<<max<<'\n';
}