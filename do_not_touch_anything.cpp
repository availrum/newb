#include<iostream>
using namespace std;
int main(){ //13136
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int R,C,N;
    cin>>R>>C>>N;
    long long int row, col;
    if(R%N!=0) row=R/N+1; 
    else row=R/N;
    if(C%N!=0) col=C/N+1;
    else col=C/N;
    cout<<row*col<<'\n';
}