#include<iostream>
#include<string>
using namespace std;
int main(){//2908
    string a,a1, b,b1;
    cin>>a>>b;
    for(int i=0; i<3; i++){
        a1[i]=a[2-i];
        b1[i]=b[2-i];
    }
    if(stoi(a1) > stoi(b1)) {
        cout<<stoi(a1)<<'\n';
        return 0;
    }
    else {
        cout<<stoi(b1)<<'\n';
        return 0;
    }
}