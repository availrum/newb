#include<iostream>
#include<cmath>
using namespace std;
int main(){//1009
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T,a,b,num;
    cin>>T;
    for(int i=0; i<T; i++){
        cin>>a>>b;
        if(a%10==1 || a%10==5 || a%10==6) cout<<a%10<<'\n';
        else if(a%10==4 || a%10==9 ) {
            if(b%2!=0) cout<<(a%10)<<'\n';
            else cout<<((a%10)*(a%10))%10<<'\n';
        }
        else if(a%10==0) cout<<"10"<<'\n';
        else {
            num=pow(a%10,((b-1)%4+1));
            cout<<num%10<<'\n';
        }
    }

}