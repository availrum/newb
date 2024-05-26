#include<iostream>
using namespace std;
int main(){//1002
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T,x1,y1,r1,x2,y2,r2,tmp,dis;
    cin>>T;
    for(int i=0; i<T; i++){
        cin>>x1>>y1>>r1>>x2>>y2>>r2;
        tmp=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
        dis=(r1+r2)*(r1+r2);
        if(tmp>dis) cout<<"0"<<'\n';
        else if(tmp==dis) cout<<"1"<<'\n';
        else {
            if(tmp>(r2-r1)*(r2-r1)) cout<<"2"<<'\n';
            else if(tmp==0 && r1==r2) cout<<"-1"<<'\n';
            else if(tmp==(r2-r1)*(r2-r1)) cout<<"1"<<'\n';
            else cout<<"0"<<'\n';
        }
    }
}