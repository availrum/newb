#include<iostream>
using namespace std;
int main(){//1300
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,k;
    cin>>N>>k;
    int st=1, ed=k, mid, sol=0;
    while(st<=ed){
        mid=(st+ed)/2;
        int cnt=0;
        for(int i=1; i<=N; ++i){
            int tmp=min(mid/i,N);
            if(tmp > 0){
                cnt+=tmp;
            }
            else break;
        }
        if(cnt < k){
            st=mid+1;
        }
        else{
            sol=mid;
            ed=mid-1;
        }
    }
    cout<<sol<<'\n';
    // for(int i=0; i<N; ++i){
    //     for(int j=0; j<N; ++j){
    //         cout<<(i+1)*(j+1)<<' ';
    //     }
    //     cout<<'\n';
    //     // cin>>t;
    // }
}