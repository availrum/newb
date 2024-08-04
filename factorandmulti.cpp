#include<iostream>
using namespace std;
int main(){//5086
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(true){
        int a,b;
        cin>>a>>b;
        if(a==0 && b==0) break;
        else if(a<b){
            if(b%a==0) cout<<"factor"<<'\n';
            else cout<<"neither"<<'\n';
        }
        else if(a>b){
            if(a%b==0) cout<<"multiple"<<'\n';
            else cout<<"neither"<<'\n';
        }
    }
}