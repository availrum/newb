#include<iostream>
using namespace std;
int arr[6200][6200];
void rec(int N, int x, int y){
    if(N==3){
        arr[x][y]=1;
        arr[x+1][y-1]=1;
        arr[x+1][y+1]=1;
        for(int i=-2; i<=2; ++i) arr[x+2][y+i]=1;
        return;
    }
    rec(N/2,x,y);
    rec(N/2, x+N/2, y-N/2);
    rec(N/2, x+N/2, y+N/2);
}
int main(){//2448
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    rec(N,0,N-1);
    for(int i=0; i<N; ++i){
        for(int j=0; j<2*N; ++j){
            if(arr[i][j]==1) cout<<"*";
            else if(i==N-1 && j==2*N-1) continue;
            else cout<<' ';
        }
        cout<<'\n';
    }
}