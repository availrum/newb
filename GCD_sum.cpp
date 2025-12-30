#include<iostream>
#define ll long long int
using namespace std;
int gcd(int a, int b){
    if(a<b) swap(a,b);
    int x=a, y=b;
    while(x%y!=0){
        int tmp=x%y;
        x=y;
        y=tmp;
    }
    // cout<<y<<'\n';
    return y;
}
int main(){ //9613
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    for(int i=0; i<t; ++i){
        int n;
        cin>>n;
        int arr[n];
        for(int j=0; j<n; ++j){
            cin>>arr[j];
        }
        ll gcdsum=0;
        for(int j=0; j<n; ++j){
            for(int k=j+1; k<n; ++k){
                gcdsum+=gcd(arr[j],arr[k]);
            }
        }
        if(n==1) gcdsum=arr[0];
        cout<<gcdsum<<'\n';
    }
} 