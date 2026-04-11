#include<iostream>
#include<vector>
using namespace std;
int fib(int n, vector<int>& arr){
    if(n<2 || arr[n]) return arr[n];
    return arr[n]=fib(n-1,arr)+fib(n-2,arr);
}
int main(){ //2302
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M,t;
    cin>>N>>M;
    //1                                                         -> 1
    //12                21                                      -> 2
    //(123 132)         213                                     -> 3
    //(1234 1243) 1324 (2134 2143)                              -> 5
    //(12345 12354) 12435 (13245 13254) (21345 21354) 21435     -> 8
    // ... 연속된 숫자가 맨뒤가 n번이면, n-1번 개수만큼 다음에 늘어나는듯
    // 사실 당연한게 n-1번째 개수만큼은 뒤에 그대로 안바꾸고 앉는 횟수랑 같음
    vector<int> arr(41,0);
    vector<bool> seat(N+1,0);
    arr[1]=1;
    arr[2]=2;

    for(int i=0; i<M; ++i){
        cin>>t;
        seat[t]=true;
    }
    int sol=1, cnt=0;
    for(int i=1; i<=N; ++i){
        if(!seat[i]) ++cnt;

        if(i==N || seat[i]){
            if(cnt) sol*=fib(cnt,arr);
            cnt=0;
        }

    }
    cout<<sol<<'\n';
    // for(int i=0; i<10; ++i){
    //     cout<<fib(i,arr)<<'\n';
    // }
}