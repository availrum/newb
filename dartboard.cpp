#include<iostream>
using namespace std;
int main(){//32400
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    double N=20, board[20];
    for(int i=0; i<N; ++i){
        cin>>board[i];
    }
    double sumalice=0,sumbob=0;
    for(int i=0; i<20; ++i){
        if(board[i]==20){
            sumalice+=20;
            if(i!=0) sumalice+=board[i-1];
            else sumalice+=board[19];

            if(i!=19) sumalice+=board[i+1];
            else sumalice+=board[0];
        }
        sumbob+=board[i];
    }
    // cout<<sumalice/3<<' '<<sumbob/20<<'\n';
    if(sumalice/3<sumbob/20) cout<<"Bob"<<'\n';
    else if(sumalice/3>sumbob/20) cout<<"Alice"<<'\n';
    else cout<<"Tie"<<'\n';
}