#include<iostream>
using namespace std;
int main(){ //29863
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int sleep, wake;
    cin>>sleep>>wake;
    if(sleep>=20) cout<<24-sleep+wake<<'\n';
    else cout<<wake-sleep<<'\n';
}