#include<iostream>
#include<cmath>
using namespace std;
int main(){
    double a1,b1,r1,a2,b2,r2,d,sol,lo,hi,the1,the2,com;
    cin>>a1>>b1>>r1>>a2>>b2>>r2;
    d=pow((a2-a1)*(a2-a1)+(b2-b1)*(b2-b1),0.5);
    lo=r1;
    hi=r2;
    // cout<<hi<<' '<<lo*lo*M_PI<<'\n';
    cout<<fixed;
    cout.precision(3);
    // cout<<0.11111<<'\n';
    if(lo>r2) {
        lo=r2;
        hi=r1;
    }
    com=pow(hi*hi-lo*lo,0.5);
    if(lo+d<=hi){//완전겹침
        cout<<pow(lo,2)*M_PI<<'\n';
        return 0;
    }
    if(r1+r2<=d) {//겹침x
        cout<<"0.000"<<'\n';
        return 0;
    }
    if(com>=d){//둔각
        the2=acos((pow(com,2)-pow(d,2))/(2*d*lo));
        the1=asin(lo*sin(the2)/hi);
        sol=(pow(lo,2)*M_PI*(2*the2/(2*M_PI))-lo*lo*sin(the2)*cos(the2))-(pow(hi,2)*M_PI*(2*the1/(2*M_PI))-hi*hi*sin(the1)*cos(the1));
        cout<<lo*lo*M_PI-sol<<'\n';
        // cout<<the2<<"com"<<the1<<'\n';
        return 0;
    }
    else{
        the2=acos((-pow(com,2)+pow(d,2))/(2*d*lo));
        the1=asin(lo*sin(the2)/hi);
    }
    sol=(pow(hi,2)*M_PI*(2*the1/(2*M_PI)))+((pow(lo,2)*M_PI*(2*the2/(2*M_PI))))-d*hi*sin(the1);
    // cout<<com<<" "<<sol<<" "<< lo<<'\n';
    cout<<sol<<'\n';
    return 0;
}