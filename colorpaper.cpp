#include<iostream>
using namespace std;
bool M[101][101];
int main(){//2563
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,x,y,cnt=0;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>x>>y;
        for(int j=0; j<10; j++){
            for(int k=0; k<10; k++){
                M[x+j][y+k]=1;
            }
        }
    }
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(M[i][j]==1) cnt++;
        }
    }
    cout<<cnt<<'\n';
}