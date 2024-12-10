#include<iostream>
using namespace std;
int main(){//10986
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    //결국 나머지의 합이 M이 되기만 하면 된다.
    //1 3 6 7 9
    //1 0 0 1 0 -> 0이 3개, 1이 2개
    //같은 나머지 끼리면 두 부분합(나머지)의 차이가 0이 되므로
    //나머지가 같은 숫자끼리 더하면(5인경우 5+4+3+2+1...N*(N-1)/2) 다른 경우도 계산된다.
    long long int arr[N], summation[N], remain[M], cnt=0;
    for(int i=0; i<M; ++i){
        remain[i]=0;
    }
    for(int i=0; i<N; ++i){
        cin>>arr[i];
        if(i==0){
            summation[i]=arr[i]%M;
        }
        else{
            summation[i]=((arr[i]%M)+(summation[i-1])%M)%M;
        }
        if(summation[i]==0){
            ++cnt;
        }
        ++remain[summation[i]];
    }
    for(int i=0; i<M; ++i){
        cnt+=(remain[i]*(remain[i]-1))/2;
    }
    cout<<cnt<<'\n';
}