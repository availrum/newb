#include<iostream>
using namespace std;
int main(){//9063
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int minx=10001,miny=10001,maxx=-10001,maxy=-10001,tx,ty;
    for(int i=0; i<N; ++i){
        cin>>tx>>ty;
        if(minx>tx) minx=tx;
        if(miny>ty) miny=ty;
        if(maxx<tx) maxx=tx;
        if(maxy<ty) maxy=ty;
    }
    cout<<(maxx-minx)*(maxy-miny)<<'\n';
}