#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){ //2294
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    int coin[n];
    for(int i=0; i<n; ++i){
        cin>>coin[i];
    }
    sort(coin,coin+n);
    vector<int> number(k+1,214748364);
    number[0]=0;
    for(int i=0; i<n; ++i){
        if(coin[i]>k) break;
        number[coin[i]]=1;
        for(int j=0; j+coin[i]<=k; ++j){
            number[j+coin[i]]=min(number[j+coin[i]], number[j]+1);
        }
    }
    if(number[k]==214748364) cout<<"-1"<<'\n';
    else cout<<number[k]<<'\n';
    // for(int i=0; i<=k; ++i) cout<<number[i]<<' ';
    // cout<<'\n';
}