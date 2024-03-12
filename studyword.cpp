#include<iostream>
#include<map>
#include<string>
using namespace std;
int uplo(int a){
    int sol;
    if(a>90) sol=a-32;
    else sol=a;
    return sol;
}
int main(){
    string a;
    char sol;
    int num=0;
    int count=0;
    map<char, int> b;
    cin>>a;
    for(int i=0; i<a.length(); i++){
        b[uplo(int(a[i]))]++;
    }
    for(int i=0; i<a.length(); i++){
        if(num<b[uplo(int(a[i]))])
            num=b[uplo(int(a[i]))];
    }
    for(int i=0; i<a.length(); i++){
        // cout<<num<<'\n';
        if(num==b[uplo(int(a[i]))] && count>num){
            cout<<"?"<<'\n';
            return 0;
        }
        if(num==b[uplo(int(a[i]))]) {
            count+=1;
            sol=a[i];
        }
    }
    cout<<char(uplo(int(sol)))<<'\n';
    return 0;
}