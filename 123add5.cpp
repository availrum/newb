#include<iostream>
#define ll long long int
using namespace std;
int main(){//15990
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll numb[100001][3];
    ll divide_number=1000000009;
    int t;
    cin>>t;
    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            numb[0][0]=0;
        }
    }
    numb[1][0]=1; //+1

    numb[2][1]=1; //+2

    numb[3][0]=1; //2+1
    numb[3][1]=1; //1+2
    numb[3][2]=1; //+3
    ll check[100001]={0,};
    check[1]=1, check[2]=1; check[3]=3;
    for(int tcase=0; tcase<t; ++tcase){
        int n;
        cin>>n;
        if(check[n]){
            cout<<check[n]<<'\n';
            continue;
        }
        for(int i=4; i<=n; ++i){
            numb[i][0]=(numb[i-1][1])%divide_number+(numb[i-1][2])%divide_number;
            numb[i][1]=(numb[i-2][0])%divide_number+(numb[i-2][2])%divide_number;
            numb[i][2]=(numb[i-3][0])%divide_number+(numb[i-3][1])%divide_number;
            check[i]=(numb[i][0]+numb[i][1]+numb[i][2])%divide_number;
        }
        cout<<check[n]<<'\n';
    }
}