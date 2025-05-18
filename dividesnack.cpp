#include<iostream>
using namespace std;
int main(){//16401
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int M,N;
    cin>>M>>N;
    int init_len=0, snack[N];
    for(int i=0; i<N; ++i){
        cin>>snack[i];
        if(snack[i]>init_len) init_len=snack[i];
    }
    int st=1, ed=init_len, mid, max_len=0;
    while(st<=ed){
        mid=(st+ed)/2;
        int have_snack=0;
        for(int i=0; i<N; ++i){
            have_snack+=snack[i]/mid;
        }
        if(have_snack<M){
            ed=mid-1;
        }
        else{
            max_len=max(max_len,mid);
            st=mid+1;
        }
    }
    cout<<max_len<<'\n';
}