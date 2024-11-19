#include<iostream>
#include<bitset>
using namespace std;
bool check2[64];
long long int squarearr[2][2];    //solution
int divide=1000000007;

void arrmult(long long int* arr, int num){
    //1차원배열->2차원으로, 길이n 이므로 인덱스는 n*i+j => i=인덱스/n, j=인덱스%n
    long long int calarr[2][2];   //^계산용
    for(int i=0; i<2; ++i) for(int j=0; j<2; ++j) calarr[i][j]=0;
    for(int i=0; i<2; ++i) for(int j=0; j<2; ++j) for(int k=0; k<2; ++k) calarr[i][j]=(calarr[i][j]+(arr[2*i+k]*arr[2*k+j])%divide)%divide;
    if(check2[num]){
        long long int tmp[2][2];
        for(int i=0; i<2; ++i) for(int j=0; j<2; ++j){
            tmp[i][j]=squarearr[i][j];
            squarearr[i][j]=0;
        }
        for(int i=0; i<2; ++i) for(int j=0; j<2; ++j) for(int k=0; k<2; ++k) squarearr[i][j]=(squarearr[i][j]+(tmp[i][k]*calarr[k][j])%divide)%divide;
    }
    for(int i=0; i<2; ++i){
        for(int j=0; j<2; ++j){
            arr[2*i+j]=calarr[i][j];
            // cout<<calarr[i][j];
            // if(j!=n-1) cout<<' ';
        }
        // cout<<'\n';
    }
    if(num!=65) arrmult(arr, num+1); // 2^37>100,000,000,000
    return;// *arr;
}

int main(){//11444
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int B;
    cin>>B;
    bitset<64> to2(B);
    for(int i=0; i<to2.size(); ++i){
        if(to2[i]==1) check2[i]=1;
        // cout<<to2[i]<<' ';
    }
    long long int arr[4]={1,1,1,0};
    squarearr[0][0]=1;

    if(check2[0]==1){
        squarearr[0][1]=1;
        squarearr[1][0]=1;
    }
    else squarearr[1][1]=1;
    arrmult(arr,1);
    cout<<squarearr[0][1]<<'\n';
}