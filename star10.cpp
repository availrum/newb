#include<iostream>
using namespace std;
int arr[6561][6561];
void rec(int N, int x, int y, int det){
    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            if(N!=3){
                if(det==0){
                    if(i==1 && j==1) rec(N/3, x+i*N/3, y+j*N/3, 1); 
                    else rec(N/3, x+i*N/3, y+j*N/3, 0);
                }
                else rec(N/3, x+i*N/3, y+j*N/3, 1);
            }
            else{
                if(det==1) arr[x+i][y+j]=1;
                else if(i==1 && j==1) arr[x+i][y+j]=1;
                else arr[x+i][y+j]=0;
            }
        }
    }
}
int main(){//2447
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    rec(N,0,0,0);
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            if(!arr[i][j]) cout<<"*";
            else if(arr[i][j]==1) cout<<' ';
        }
        cout<<'\n';
    }
}