#include<iostream>
#include<bitset>
using namespace std;
bool check2[64];
int squarearr[6][6];    //solution
int divide=1000;
void arrmult(int* arr, int n, int num){
    //1차원배열->2차원으로, 길이n 이므로 인덱스는 n*i+j => i=인덱스/n, j=인덱스%n
    int calarr[n][n];   //^계산용
    for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) calarr[i][j]=0;
    for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) for(int k=0; k<n; ++k) calarr[i][j]=(calarr[i][j]+(arr[n*i+k]*arr[n*k+j])%divide)%divide;
    if(check2[num]){
        int tmp[n][n];
        for(int i=0; i<n; ++i) for(int j=0; j<n; ++j){
            tmp[i][j]=squarearr[i][j];
            squarearr[i][j]=0;
        }
        for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) for(int k=0; k<n; ++k) squarearr[i][j]=(squarearr[i][j]+(tmp[i][k]*calarr[k][j])%divide)%divide;
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            arr[n*i+j]=calarr[i][j];
            // cout<<calarr[i][j];
            // if(j!=n-1) cout<<' ';
        }
        // cout<<'\n';
    }
    if(num!=40) arrmult(arr, n, num+1); // 2^37>100,000,000,000
    return;// *arr;
}
int main(){//10830
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    long long int B;
    cin>>N>>B;
    bitset<64> to2(B);
    // cout<<to2<<'\n'; 1 2 4 8 16 32 
    // for(int i=to2.size()-1; i>=0; --i){
    
    for(int i=0; i<to2.size(); ++i){
        if(to2[i]==1) check2[i]=1;
        // cout<<to2[i]<<' ';
    }
    // int sum=0;
    // for(int i=0; i<to2.size(); ++i) cout<< check2[i]<<' ';
    // cout<<'\n';
    
    int arr[N*N],cnt=0;
    for(int i=0; i<N; ++i) for(int j=0; j<N; ++j){
        cin>>arr[N*i+j];
        if(check2[0]==1) squarearr[i][j]=arr[N*i+j];
        else if(i==j) squarearr[i][j]=1;
        if(arr[N*i+j]==1000) ++cnt;
    }
    if(cnt==N*N){
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                cout<<"0";
                if(j!=N-1) cout<<' ';
                else cout<<'\n';
            }
        }
        return 0;
    }
    arrmult(arr,N,1);
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cout<<squarearr[i][j];
            if(j!=N-1) cout<<' ';
        }
        cout<<'\n';
    }
}