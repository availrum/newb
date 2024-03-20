#include<iostream>
using namespace std;
int main(){
    int test;
    int b[5][15];
    for(int i=0; i<5; i++){
        for(int j=0; j<15; j++){
            b[i][j]=0;
        }
    }
    string a;
    for(int i=0; i<5; i++){
        cin>>a;
        for(int j=0; j<a.length(); j++){
            b[i][j]=a[j];
        }
    }
    for(int i=0; i<15; i++){
        for(int j=0; j<5; j++){
        if(b[j][i]==0) continue;
            cout<< char(b[j][i]) ;
        }
    }
    cout<<'\n';
    return 0;
}