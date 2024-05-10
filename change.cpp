#include<iostream>
int check(int a, int b){
    return a>b ? a:b;
}
using namespace std;
int main(){//5585
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    int y=0;
    cin>>N;
    N=1000-N;
    if(N>=500){
        y+=N/500;
        N=N%500;
    }
    if(N>=100){
        y+=N/100;
        N=N%100;
    }
    if(N>=50){
        y+=N/50;
        N=N%50;
    }
    if(N>=10){
        y+=N/10;
        N=N%10;
    }
    if(N>=5){
        y+=N/5;
        N=N%5;
    }
    y+=N;
    cout<<y<<'\n';
}