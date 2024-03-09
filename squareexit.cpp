#include<iostream>
#include<algorithm>
using namespace std;
int main(){//1085
    int x,y,w,h;
    int a;
    cin>>x>>y>>w>>h;
    a=x;
    if(w-x<a) a=w-x;
    if(y<a) a=y;
    if(h-y<a) a=h-y;

    cout<<a<<'\n';
    
}