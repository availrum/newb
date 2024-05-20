#include<iostream>
// #include<map>
#include<vector>
using namespace std;
// map<vector<int>,int> ma;
int arr[1001][1001];
int main(){//11051
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // cout.tie(NULL);
    int N,K,num=1,divi=10007;
    cin>>N>>K;
    // ma[{0,0}]=1;
    // ma[{1,0}]=1;
    // ma[{1,1}]=1;
    arr[0][0]=1;
    arr[1][0]=1;
    arr[1][1]=1;
    for(int i=2; i<=N; i++){
        // ma[{i,0}]=1;
        // ma[{i,i}]=1;
        arr[i][i]=1;
        arr[i][0]=1;
        for(int j=1; j<=i; j++){
            if(j>K) break;
            // ma[{i,j}]=((ma[{i-1,j-1}]%divi)+(ma[{i-1,j}])%divi)%divi;
            arr[i][j]=((arr[i-1][j-1]%divi)+(arr[i-1][j])%divi)%divi;
        }
    }
    cout<<arr[N][K]<<'\n';
}