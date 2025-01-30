#include<iostream>
using namespace std;
int main(){//7561
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int tcase=0; tcase<T; ++tcase){
        long int eq1[4], eq2[4], eq3[4];
        for(int i=0; i<4; ++i){
            cin>>eq1[i];
        }
        for(int i=0; i<4; ++i){
            cin>>eq2[i];
        }
        for(int i=0; i<4; ++i){
            cin>>eq3[i];
        }
        long int detA=eq1[0]*(eq2[1]*eq3[2]-eq2[2]*eq3[1])-eq1[1]*(eq2[0]*eq3[2]-eq2[2]*eq3[0])+eq1[2]*(eq2[0]*eq3[1]-eq2[1]*eq3[0]);
        long int detA1=eq1[3]*(eq2[1]*eq3[2]-eq2[2]*eq3[1])-eq1[1]*(eq2[3]*eq3[2]-eq2[2]*eq3[3])+eq1[2]*(eq2[3]*eq3[1]-eq2[1]*eq3[3]);
        long int detA2=eq1[0]*(eq2[3]*eq3[2]-eq2[2]*eq3[3])-eq1[3]*(eq2[0]*eq3[2]-eq2[2]*eq3[0])+eq1[2]*(eq2[0]*eq3[3]-eq2[3]*eq3[0]);
        long int detA3=eq1[0]*(eq2[1]*eq3[3]-eq2[3]*eq3[1])-eq1[1]*(eq2[0]*eq3[3]-eq2[3]*eq3[0])+eq1[3]*(eq2[0]*eq3[1]-eq2[1]*eq3[0]);

        cout<<detA1<<' '<<detA2<<' '<<detA3<<' '<<detA<<'\n';
        if(detA==0){
            cout<<"No unique solution"<<'\n';
        }
        else{
            double sol1=(double)detA1/detA, sol2=(double)detA2/detA, sol3=(double)detA3/detA;
            sol1+=0;
            sol2+=0;
            sol3+=0;
            cout.precision(3);
            cout<<fixed;
            cout<<"Unique solution: "<<sol1<<' '<<sol2<<' '<<sol3<<'\n';
        }
        if(tcase!=T-1) cout<<'\n';
        cout.unsetf(ios::fixed);
    }
}