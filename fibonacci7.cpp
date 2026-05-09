#include<iostream>
#include<vector>
using namespace std;
const int divid=1000000007;
int fib(int n, vector<int>& arr){
    if(arr[n] || n==0) return arr[n];
    return arr[n]=(fib(n-1,arr)%divid+fib(n-2,arr)%divid)%divid;
}
int main(){ //15624
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,t;
    cin>>N;
    vector<int> arr(N+2,0);
    arr[1]=1;
    cout<<fib(N,arr)<<'\n';
}