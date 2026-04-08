#include<iostream>
#include<vector>
using namespace std;
int main(){ //2631
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    vector<int> arr(N),cnt(N,0);
    for(int i=0; i<N; ++i){
        cin>>arr[i];
    }
    int max_cnt=0;
    for(int i=0; i<N; ++i){
        for(int j=i; j>=0; --j){
            if(arr[i]>=arr[j]) cnt[i]=max(cnt[i],cnt[j]+1);
        }
        max_cnt=max(max_cnt,cnt[i]);
    }
    cout<<N-max_cnt<<'\n';
}