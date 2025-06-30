#include<iostream>
#include<unordered_map>
using namespace std;
int main(){ //20922
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,K;
    cin>>N>>K;
    int arr[N+1]={0,};
    for(int i=0; i<N; ++i){
        cin>>arr[i];
    }
    unordered_map<int,int> check;
    int lft=0, rgt=0, max_length=0;
    ++check[arr[rgt]];
    while(lft<N){
        if(check[arr[rgt]]>K){
            --check[arr[lft]];
            ++lft;
        }
        else{
            max_length=max(max_length, rgt-lft+1);
            if(rgt<N-1){
                ++rgt;
                ++check[arr[rgt]];
            }
            else break;
        }
        // cout<<lft<<' '<<rgt<<' '<<check[arr[rgt]]<<'\n';
    }
    cout<<max_length<<'\n';
}