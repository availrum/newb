#include<iostream>
#include<map>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M,val;
    long long int x;
    map<long long int, int> a;
    cin>>N;
    for(int i=1; i<=N; i++){
        cin>>x;
        a[x]++;
    }
    cin>>M;
    for(int j=1; j<=M; j++){
        cin>>val;
        if(a[val]>0){
            cout<<"1"<<'\n';
        }
        else cout<<"0"<<'\n';
    }
    return 0;
}