#include<iostream>
using namespace std;
int main(){//2775
    int test,k,n;
    int a[15][15];
    for(int i=0; i<15; i++){
        a[i][0]=1;
        a[0][i]=i+1;
    }
    cin>>test;
    for(int l=0; l<test; l++){
        cin>>k>>n;//n-0, k-1
        if(n==1){
            cout<<1<<'\n';
            continue;
        }
        for(int i=1; i<=k; i++){//row
            for(int j=1; j<=n; j++){//column
                a[i][j]=a[i][j-1]+a[i-1][j];
            }
        }
        cout<<a[k][n-1]<<'\n';
    }
    return 0;
}