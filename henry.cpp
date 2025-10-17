#include<iostream>
using namespace std;
void reduced_fraction(int &a, int &b){
    int x=a, y=b;
    if(x>y) swap(x,y);
    // cout<<x<<' '<<y<<'\n';
    while(y%x!=0){
        int tmp=y%x;
        y=x;
        x=tmp;
    }
    if(x==0) return;
    a/=x;
    b/=x;
}
int main(){ //10253
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int tcase=0; tcase<T; ++tcase){
        int a,b;
        cin>>a>>b;
        int x;
        while(a>0){// (a/b>=1/i -> i>=b/a)
            x=b/a;
            if(b%a!=0) ++x;
            a=a*x-b;
            b*=x;
            if(a!=0) reduced_fraction(a,b);
            else break;
        }
        cout<<x<<'\n';
    }
}