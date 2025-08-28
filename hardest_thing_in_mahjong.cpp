#include<iostream>
using namespace std;
int main(){ //33049
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N=0,p3,p4,p0;
    cin>>p3>>p4>>p0;
    int t3, t4;
    if(p3%3==0){
        t3=p3/3;
    }
    else{
        t3=1+p3/3;
        p0-=3-(p3%3);
    }

    if(p4%4==0){
        t4=p4/4;
    }
    else{
        t4=1+p4/4;
        p0-=4-(p4%4);
    }

    while(p0>=0){
        if(p0%4==0){
            t4+=(p0/4);
            p0=0;
            break;
        }
        ++t3;
        p0-=3;
    }

    if(p0<0){
        cout<<"-1\n";
        return 0;
    }

    cout<<t3<<' '<<t4<<'\n';
}