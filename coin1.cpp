#include<iostream>
#include<algorithm>
using namespace std;
int main(){ //2293
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    int value[n];
    for(int i=0; i<n; ++i){
        cin>>value[i];
    }
    sort(value,value+n);
    int cnt[k+1]={0,};
    for(int i=0; i<n; ++i){
        for(int j=1; j<=k; ++j){
            if(j-value[i]<0) continue;
            else if(j==value[i]) ++cnt[j];
            else cnt[j]+=cnt[j-value[i]];
        }
    }
    cout<<cnt[k]<<'\n';
}