#include<iostream>
using namespace std;
int main(){//1912
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int arr[N],summ[N],maxsum=-1001;
    for(int i=0; i<N; ++i){
        cin>>arr[i];
        if(i==0) summ[i]=arr[i];
        else if(i!=0) summ[i]=max(summ[i-1]+arr[i],arr[i]);
        if(maxsum<summ[i]) maxsum=summ[i];
    }
    cout<<maxsum<<'\n';
}