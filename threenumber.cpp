#include<iostream>
#include<algorithm>
using namespace std;
int main(){//10817
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int arr[3];
    cin>>arr[0]>>arr[1]>>arr[2];
    sort(arr,arr+3);
    cout<<arr[1]<<'\n';
}