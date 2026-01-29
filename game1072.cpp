#include<iostream>
#define ll long long int
using namespace std;
int main(){ //1072
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll X,Y,lose;
    cin>>X>>Y;
    lose=X-Y;
    ll Z=(Y*100)/X;
    // cout<<Z<<'\n';
    if(Z==99 || Z==100){
        cout<<"-1\n";
        return 0;
    }
    // X-Y=lose, (X+par)-(Y+par)=lose
    // 100*(Y+par)/(Y+par+lose) = (Z+1)
    // (Z+1)*(Y) + (Z+1)*par + (Z+1)*lose = 100*Y+100*par
    // (99-Z)*par = (Z-99)*Y + (Z+1)*lose
    // par=((Z-99)*Y+(Z+1*lose))/(99-Z)
    ll play_game;
    if(((Z+1)*lose)%(99-Z)==0) play_game=((Z+1)*lose)/(99-Z)-Y;
    else play_game=((Z+1)*lose)/(99-Z)-Y+1;

    cout<<play_game<<'\n';
}