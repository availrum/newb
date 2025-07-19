#include<iostream>
using namespace std;
int main(){ //13144
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int arr[N], cnt[N+1]={0,};
    for(int i=0; i<N; ++i){
        cin>>arr[i];
    }
    int lft=0, rgt=0;
    long long int sol=0;
    ++cnt[arr[lft]];
    while(lft<N){
        if(rgt>=N) break;

        if(cnt[arr[rgt]]<2 && rgt<N-1){
            ++rgt;
            if(rgt<N) ++cnt[arr[rgt]];
        }
        else if(cnt[arr[rgt]]<2 && rgt==N-1){
            sol+=(rgt-lft+1);
            --cnt[arr[lft]];
            ++lft;
        }
        else{
            sol+=(rgt-lft);
            --cnt[arr[lft]];
            ++lft;
        }
        // cout<<"lft="<<lft<<", rgt="<<rgt<<", total="<<sol<<'\n';
    }
    cout<<sol<<'\n';
}