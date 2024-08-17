#include<iostream>
#include<algorithm>
using namespace std;
int main(){//3009
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x[3],y[3],mx=0,my=0;
    for(int i=0; i<3; ++i) cin>>x[i]>>y[i];
    sort(x,x+3);
    sort(y,y+3);
    if(x[1]==x[0]) mx=x[2];
    else mx=x[0];
    if(y[1]==y[0]) my=y[2];
    else my=y[0];
    cout<<mx<<' '<<my<<'\n';
}