#include<iostream>
int check(int a, int b){
    return a>b ? a:b;
}
using namespace std;
int main(){//4796
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int L,P,V;
    int i=0;
    while(true){
        i++;
        int tot=0;
        cin>>L>>P>>V;
        if(L==0 && P==0 && V==0) break;
        tot+=L*(V/P);
        if(V%P>=L) tot+=L;
        else tot+=(V%P);
        cout<<"Case "<<i<<": "<<tot<<'\n';
    }
}