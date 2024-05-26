#include<iostream>
using namespace std;
int main(){//9461
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int T, arr[101],N,max=3;
    cin>>T;
    arr[1]=1;
    arr[2]=1;
    arr[3]=1;
    for(int i=0; i<T; i++){
        cin>>N;
        if(max>N) cout<<arr[N]<<'\n';
        else if(N>max||max==3){
            for(int j=4; j<=N; j++){
                arr[j]=arr[j-2]+arr[j-3];
            }
            max=N;
            cout<<arr[N]<<'\n';
        }
    }

}