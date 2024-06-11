#include<iostream>
using namespace std;
// 붙어있는 집의 색상과 다르게
int cmp(int a, int b){
    return a<b ? a:b; 
}
int minimum(int a, int b, int c){
    int tmp=a;
    if(tmp>b) tmp=b;
    if(tmp>c) tmp=c;
    return tmp;
}
int main(){//1149
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,r,g,b;
    cin>>N;
    int arr[N][N],min[N+1][N+1],sol[N];
    for(int i=0; i<N; i++){
        for(int j=0; j<3; j++){
            cin>>arr[i][j];
        }
    }
    min[1][0]=cmp(arr[0][1]+arr[1][0], arr[0][2]+arr[1][0]);
    min[1][1]=cmp(arr[0][0]+arr[1][1], arr[0][2]+arr[1][1]);
    min[1][2]=cmp(arr[0][0]+arr[1][2], arr[0][1]+arr[1][2]);
    sol[1]=minimum(min[1][0],min[1][1],min[1][2]);
    for(int i=2; i<N; i++){
        min[i][0]=cmp(min[i-1][1]+arr[i][0], min[i-1][2]+arr[i][0]);
        min[i][1]=cmp(min[i-1][0]+arr[i][1], min[i-1][2]+arr[i][1]);
        min[i][2]=cmp(min[i-1][0]+arr[i][2], min[i-1][1]+arr[i][2]);
        sol[i]=minimum(min[i][0],min[i][1],min[i][2]);
    }
    // cout<<min[N-1][0]<<' '<<min[N-1][1]<<' '<<min[N-1][2]<<'\n';
    cout<<sol[N-1]<<'\n';
}