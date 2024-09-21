#include<iostream>
using namespace std;
int main(){//1806
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,S;
    cin>>N>>S;
    int arr[N]={0,};
    for(int i=0; i<N; ++i) cin>>arr[i];
    int st=0, ed=0, leng=0, sum=arr[st];
    while(ed<N){
        if(sum>=S){
            if(leng==0 || leng>ed-st+1) leng=ed-st+1;
            sum-=arr[st];
            ++st;
        }
        else{
            ++ed;
            sum+=arr[ed];
        }
    }
    cout<<leng<<'\n';
}