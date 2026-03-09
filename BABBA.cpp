#include<iostream>
using namespace std;
int main(){ //9625
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int K;
    cin>>K;
    int numa=1, numb=0, tmpa, tmpb;
    for(int i=0; i<K; ++i){
        tmpa=numb-numa;
        tmpb=numa;
        numa+=tmpa;
        numb+=tmpb;
    }
    cout<<numa<<' '<<numb<<'\n';
}