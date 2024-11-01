#include<iostream>
using namespace std;
int main(){//2083
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string st;
    int age, weight;
    while(true){
        cin>>st>>age>>weight;
        if(st=="#" && age==0 && weight==0) break;
        if(age>17 || weight>=80){
            cout<<st<<' '<<"Senior"<<'\n';
        }
        else cout<<st<<' '<<"Junior"<<'\n';
    }
}