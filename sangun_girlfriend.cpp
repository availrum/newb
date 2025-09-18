#include<iostream>
#include<cmath>
using namespace std;
double func(double a, double b, double c, double d, double t, double m, double val){
    return a*pow(val,3)+b*pow(val,2)+c*val+d-t/m;
}
double func_prime(double a, double b, double c, double d, double t, double m, double val){
    return 3*a*pow(val,2)+2*b*val+c;
}
int main(){ //4454
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long double a,b,c,d,m,t;
    while(cin>>a>>b>>c>>d>>m>>t){
        // if(a==-1111) break;
        double val=m;
        for(int i=0; i<100; ++i){
            val=val-func(a,b,c,d,t,m,val)/func_prime(a,b,c,d,t,m,val);
        }
        val=floor(val*100);
        val/=100;
        cout.precision(2);
        cout<<fixed;
        cout<<val<<'\n';
    }
}