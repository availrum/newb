#include <iostream>
using namespace std;
int main(){//9465
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T,n;
    cin>>T;
    for(int i=0; i<T; ++i){
        cin>>n;
        int arr[2][n]={0,},sol[2][n]={0,};
        for(int j=0; j<n; ++j) cin>>arr[0][j];
        for(int j=0; j<n; ++j) cin>>arr[1][j];//점수입력
        sol[0][0]=arr[0][0];
        sol[1][0]=arr[1][0];
        if(n==1){
            cout<<max(sol[0][0],sol[1][0])<<'\n';
            continue;
        }
        sol[0][1]=sol[1][0]+arr[0][1];
        sol[1][1]=sol[0][0]+arr[1][1];
        for(int j=2; j<n; ++j){
            sol[0][j]=max(sol[1][j-2]+arr[0][j],sol[1][j-1]+arr[0][j]);
            sol[1][j]=max(sol[0][j-2]+arr[1][j],sol[0][j-1]+arr[1][j]);
        }
        cout<<max(sol[0][n-1],sol[1][n-1])<<'\n';
    }
    return 0;
}