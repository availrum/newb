#include<iostream>
using namespace std;
int main(){ //1476
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int E,S,M;
    cin>>E>>S>>M;
    //E-15(%16), S-28(%29), M-19(%20)
    //1 16 16 / 5 20 1 / 14 1 10
    int curE=1, curS=1, curM=1, year=1;
    for(int i=1; i<=7980; ++i){
        if(curE==E && curS==S && curM==M) break;
        ++curE;
        ++curS;
        ++curM;
        ++year;
        if(curE>15) curE=1;
        if(curS>28) curS=1;
        if(curM>19) curM=1;
        if(curE==E && curS==S && curM==M) break;
    } 
    cout<<year<<'\n';
}