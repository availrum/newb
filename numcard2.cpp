#include<iostream>
#include<map>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M,xn,xm;
    int c=10000000;
    map<int, int> a;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>xn;
        a[xn+c]++;
    }
    cin>>M;
    for(int i=0; i<M; i++){
        cin>>xm;
        cout<<a[xm+c]<<' ';
    }
    cout<<'\n';
    return 0;
}