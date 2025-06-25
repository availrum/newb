#include<iostream>
#include<cmath>
using namespace std;
//2pi=
int main(){ //1876
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    for(int i=0; i<N; ++i){
        double T,X;
        cin>>T>>X;
        double angle=M_PI/180*X;
        T*=100;
        // if(X==0) cout<<"yes"<<'\n';

        double dist=42.5/tan(angle);
        int quotient;
        if(abs(round(T/dist)-T/dist)>1e-6) quotient=T/dist;
        else quotient=abs(round(T/dist));
        double remain_dist=T-quotient*dist;
        cout.precision(2);
        cout<<fixed;
        // cout<<T/dist<<" and "<<quotient<<'\n';

        if(quotient%2==0){
            // cout<<"even"<<'\n';
            if(sin(angle)*remain_dist<=16){
                cout<<"yes"<<'\n';
            }
            else cout<<"no"<<'\n';
        }
        else{
            // cout<<"odd"<<'\n';
            double diff=abs(42.5-tan(angle)*remain_dist) *cos(angle);
            if(diff<=16){
                cout<<"yes"<<'\n';
            }
            else cout<<"no"<<'\n';
        }
        // cout<<sin(M_PI/180*X)<<'\n';
    }
}