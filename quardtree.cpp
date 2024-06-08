#include<iostream>
using namespace std;
int arr[65][65];
void quard(int a, int b, int n){
    if(n==1){
        cout<<arr[a][b];
        return;
    }
    int flag0=0, flag1=0;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(flag0==0 && arr[a+i][b+j]==0) flag0=1;
            if(flag1==0 && arr[a+i][b+j]==1) flag1=1;
        }
    }
    if((flag1+flag0)==1){
        cout<<arr[a][b];
        return;
    }
    cout<<"(";
    quard(a,b,n/2);
    quard(a,b+n/2,n/2);
    quard(a+n/2,b,n/2);
    quard(a+n/2,b+n/2,n/2);
    cout<<")";
    
}
int main(){//1992
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,tmp;
    string st;
    cin>>N;
    for(int i=0; i<N; ++i){
        cin>>st;
        for(int j=0; j<N; ++j) arr[i][j]=st[j]-48;   
    }
    quard(0,0,N);
    cout<<'\n';
}