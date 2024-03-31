#include<iostream>
#include<map>
using namespace std;
int cnt0=0, cnt1=0;
map<int, int> tmp,num0,num1;

// int bonac(int n){
//     if(n==0) {
//         cnt0++;
//         num0[n]++;
//         return 0; 
//     }
//     else if(n==1) {//eventually, 1 value goes to fib(n) 
//         cnt1++;
//         num1[n]++;
//         return 1;
//     }
//     else{
//         if(tmp[n]!=0){
//             n=tmp[n];
//         }
//         else{
//             tmp[n]=bonac(n-1)+bonac(n-2);
//             n=tmp[n];
//         }
//     }
//     return n;
// } 
int main(){//1003
    int N,test,tmp;
    cin>>test;
    for(int i=0; i<test; i++){
        cnt0=0;
        cnt1=0;
        cin>>N;
        // bonac(N);
        num0[0]=1;
        num0[1]=0;
        num1[0]=0;
        num1[1]=1;
        for(int j=2; j<=N; j++){
            num0[j]=num0[j-1]+num0[j-2];
            num1[j]=num1[j-1]+num1[j-2];
        }
        // cout<<cnt0<<' '<<cnt1<<'\n';
        cout<<num0[N]<<' '<<num1[N]<<'\n';
        // cout<<bonac(N)<<'\n';
    }
    return 0;
}