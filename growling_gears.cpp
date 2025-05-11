#include<iostream>
using namespace std;
int main(){//10325
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    cin>>test_case;
    for(int tcase=0; tcase<test_case; ++tcase){
        long double N;
        cin>>N;
        long double a,b,c;
        long double max_rpm, max_torque_value=-2147483647;
        int max_torque_idx;
        for(int i=1; i<=N; ++i){ //a*2*R=b -> R=b/(2*a)
            cin>>a>>b>>c;
            max_rpm=b/(2*a);
            long double current_torque= -a*(max_rpm*max_rpm)+b*max_rpm+c;
            if(current_torque>max_torque_value){
                max_torque_value=current_torque;
                max_torque_idx=i;
            }
        }
        cout<<max_torque_idx<<'\n';
    }
}