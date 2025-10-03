#include<iostream>
using namespace std;
int main(){ //13987
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int A[6],B[6];
    for(int i=0; i<6; ++i) cin>>A[i];
    for(int i=0; i<6; ++i) cin>>B[i];
    double player1_win=0, player2_win=0;
    for(int i=0; i<6; ++i){
        for(int j=0; j<6; ++j){
            if(A[i]==B[j]) continue;
            else if(A[i]>B[j]) player1_win+=1;
            else if(A[i]<B[j]) player2_win+=1;
        }
    }
    double sol=player1_win/(player1_win+player2_win);
    cout.precision(5);
    cout<<fixed;
    cout<<sol<<'\n';
}