#include<iostream>
using namespace std;
int main(){ //11057
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int num[N][10];
    const int div=10007;
    for(int i=0; i<N; ++i){
        for(int j=0; j<10; ++j){
            if(i==0) num[i][j]=1;
            else num[i][j]=0;
        }
    }
    for(int i=1; i<N; ++i){
        for(int j=0; j<10; ++j){
            for(int k=j; k>=0; --k){
                num[i][j]=((num[i][j]%div)+(num[i-1][k]%div))%div;
            }
        }
    }
    int sol=0;
    for(int i=0; i<10; ++i){
        sol=((sol%div)+(num[N-1][i]%div))%div;
    }
    cout<<sol<<'\n';
} 