#include<iostream>
using namespace std;
int main(){//30875
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,t;
    cin>>N;
    int board[N]={0,};
    for(int i=0; i<N; ++i) for(int j=0; j<N; ++j){
        cin>>t;
        ++board[t];
    }
    int tmp=0;
    for(int i=1; i<=N; ++i){
        while(board[i]){
            cout<<i;
            --board[i];
            ++tmp;
            if(tmp%N==0){
                cout<<'\n';
                break;
            }
            else cout<<' ';
        }
    }
}