#include<iostream>
using namespace std;
int main(){
    string a;
    cin>>a;
    if(a.length()==1) {
        cout<<'1'<<'\n';
        return 0;
    }
    for(int i=0; i<a.length(); i++){
        if(i>=a.length()-1-i) break;
        if(a[i]!=a[a.length()-1-i]){
            cout<<'0'<<'\n';
            return 0;
        }
    }
    cout<<'1'<<'\n';
    return 0;
}