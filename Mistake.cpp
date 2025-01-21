#include<iostream>
using namespace std;
int main(){//21917
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k,m;
    cin>>n>>k>>m;
    int a,b;
    for(int i=0; i<m; ++i){
        cin>>a>>b;
    }
    int log[n*k], cur[n+1]={0,};
    for(int i=0; i<n*k; ++i){
        cin>>log[i];
        ++cur[log[i]];
        cout<<cur[log[i]];
        if(i!=n*k-1) cout<<' ';
        else cout<<'\n';
    }
}