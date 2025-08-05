#include<iostream>
using namespace std;
int main(){ //28065
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int arr[N];
    int maxi=N, mini=1;
    for(int i=0; i<N; ++i){
        if(i%2==0){
            arr[i]=mini;
            ++mini;
        }
        else{
            arr[i]=maxi;
            --maxi;
        }
    }
    for(int i=0; i<N; ++i){
        cout<<arr[i];
        if(i!=N-1) cout<<' ';
    }
    cout<<'\n';
}