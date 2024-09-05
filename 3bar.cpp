#include<iostream>
#include<algorithm>
using namespace std;
int main(){//14215
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tri[3];
    for(int i=0; i<3; ++i) cin>>tri[i];
    sort(tri,tri+3);
    if(tri[0]+tri[1]>tri[2]) cout<<tri[0]+tri[1]+tri[2]<<'\n';
    else cout<<2*(tri[0]+tri[1])-1<<'\n';
}