#include<iostream>
#include<algorithm>
using namespace std;
int main(){//16208
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    long long int stick[n];
    long long int cost=0, sum=0;
    for(int i=0; i<n; ++i){
        cin>>stick[i];
        sum+=stick[i];
    }
    sort(stick,stick+n);
    for(int i=0; i<n-1; ++i){
        // cost+=stick[i]*stick[i+1];
        sum-=stick[i];
        cost+=stick[i]*sum;
    }
    cout<<cost<<'\n';
}