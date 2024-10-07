#include<iostream>
using namespace std;
int main(){//10844
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    long int stair[N+1][10];
    // stair[0]=9;
    //10 12 21 23 32 / 34 43 45 54 56 / 65 67 76 78 87 / 89 98 (90x)=17
    // stair[1]=17;
    //(109) 101 121 123 210 213 232 234 321 323 =9/ 343 345 432 434 454 456 543 545 565 567 =10
    // 654 653 676 678 765 767 787 789 876 878=10 / 898 (890) 987 989 =3 
    //끝이 0인것과 9인 경우만큼 빼기
    for(int i=0; i<N; ++i){
        for(int j=0; j<10; ++j){
            if(i==0 && j!=0) stair[i][j]=1;
            else stair[i][j]=0;
        }
    }
    for(int i=1; i<=9; ++i) stair[0][i]=1;
    
    for(int i=1; i<N; ++i){
        for(int j=0; j<=9; ++j){
            if(j!=0 && j!=9){
                stair[i][j+1]=(stair[i][j+1]+stair[i-1][j])%1000000000;
                stair[i][j-1]=(stair[i][j-1]+stair[i-1][j])%1000000000;
            }
            else if(j==0) stair[i][j+1]=(stair[i][j+1]+stair[i-1][j])%1000000000;
            else if(j==9) stair[i][j-1]=(stair[i][j-1]+stair[i-1][j])%1000000000;
        }
    }
    long int sum=0;
    for(int i=0; i<=9; ++i){
        sum=(sum+(stair[N-1][i]))%1000000000;
        // cout<<stair[N-1][i]<<'\n';
    }
    cout<<sum<<'\n';
}