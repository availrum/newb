#include<iostream>
using namespace std;
int main(){ //23028
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,A,B;
    cin>>N>>A>>B;
    int major=66-A, total=130-B;
    int X,Y;
    for(int i=0; i<10; ++i){
        cin>>X>>Y;
        if(8-N-i>0){
            major-=min(18,3*X);
            total-=min(18,3*(X+Y));
        }
    }
    if(major<=0 && total<=0) cout<<"Nice"<<'\n';
    else cout<<"Nae ga wae"<<'\n';
}