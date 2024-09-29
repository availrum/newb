#include<iostream>
#include<cmath>
using namespace std;
void rec(int N,int st){
    if(N==1){
        cout<<"-";
        return;
    }
    int tmp=N/3;
    rec(tmp,st);
    for(int i=0; i<tmp; ++i) cout<<' ';
    rec(tmp,st+tmp*2);
}
int main(){//4779
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    while(cin>>N){
        // if(N==-1) break;
        rec(pow(3,N),0);
        cout<<'\n';
    }
}