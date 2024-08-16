#include<iostream>
using namespace std;
int main(){//2133
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,t;
    cin>>N;
    int arr[N]={0,};
    arr[0]=0;
    arr[1]=3; 
    arr[2]=0;
    arr[3]=11;
    for(int i=2; i<N; i++){
        if(i%2==0) continue;
        else{
            arr[i]=arr[i-2]*3+2;
            for(int j=i-4; j>=0; j-=2) arr[i]+=2*arr[j];
        }
    }
    cout<<arr[N-1]<<'\n';
}