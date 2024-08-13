#include<iostream>
#include<algorithm>
using namespace std;
int main(){//3273
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,cnt=0,num;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; ++i) cin>>arr[i];
    cin>>num;
    sort(arr,arr+n);
    int li=0, ri=n-1;
    while(li<ri){
        if(arr[li]+arr[ri]==num){
            ++cnt;
            ++li;
            --ri;
        }
        else if(arr[li]+arr[ri]>num) --ri;
        else if(arr[li]+arr[ri]<num) ++li;
    }
    cout<<cnt<<'\n';
}