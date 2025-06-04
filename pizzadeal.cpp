#include<iostream>
#include<cmath>
using namespace std;
int main(){//16693
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    double A,P1 , R1,P2;
    cin>>A>>P1>>R1>>P2;
    double Pizza1=A/P1;
    double Pizza2=R1*R1*M_PI/P2;
    // cout<<M_PI<<'\n';
    if(Pizza1>Pizza2) cout<<"Slice of pizza"<<'\n';
    else cout<<"Whole pizza"<<'\n';
}