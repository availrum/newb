#include<iostream>
using namespace std;
int arr[2201][2201];
int cntm1,cnt0,cnt1;
int rec(int a, int b, int N){
    if(N==1){
        return arr[a][b];
    }
    bool flag=false;
    int tmp=5;
    int tarr[3]={0, 0, 0};
    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            int x=rec(a+i*(N/3), b+j*(N/3), N/3);
            if(i==0 && j==0){
                tmp=x;
            }
            if(x!=tmp || x==2) flag=true;
            tmp=x;
            
            if(x==1) ++tarr[0];
            else if(x==0) ++tarr[1];
            else if(x==-1) ++tarr[2];
        }
    }
    if(flag){
        cnt1+=tarr[0];
        cnt0+=tarr[1];
        cntm1+=tarr[2];
        return 2;
    }
    else{
        return arr[a][b];
    }
}
int main(){//1780
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tt;
    cin>>tt;
    const int N=tt;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin>>arr[i][j];
        }
    }
    rec(0,0,N);
    if(cnt0==0 && cnt1==0 && cntm1==0){
        if(arr[0][0]==1) cnt1=1;
        else if(arr[0][0]==0) cnt0=1;
        else cntm1=1;
    }
    cout<<cntm1<<'\n';
    cout<<cnt0<<'\n';
    cout<<cnt1<<'\n';
}