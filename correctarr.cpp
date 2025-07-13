#include<iostream>
#include<algorithm>
using namespace std;
int main(){ //1337
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int arr[N];
    for(int i=0; i<N; ++i){
        cin>>arr[i];
    }
    sort(arr,arr+N);
    int need=4;
    int lft=0, rgt=0;
    while(lft<N){
        if(rgt >= N) break;

        if(arr[rgt]-arr[lft]<5){
            need=min(need,5-(rgt-lft+1));
            ++rgt;
        }
        else ++lft;
        // cout<<lft<<' '<<rgt<<' '<<need<<'\n';
        // cout<<(rgt-lft+1)<<'\n';
    }
    cout<<need<<'\n';
}