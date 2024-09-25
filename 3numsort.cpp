#include<iostream>
#include<algorithm>
using namespace std;
int main(){//2752
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int arr[3];
    for(int i=0; i<3; ++i) cin>>arr[i];
    sort(arr,arr+3);
    for(int i=0; i<3; ++i){
        cout<<arr[i];
        if(i!=2) cout<<' ';
        else cout<<'\n';
    }
}