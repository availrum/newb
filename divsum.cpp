#include<iostream>
using namespace std;
int main(){
    int N, a,b ;
    cin>>N;
    int c;
    b=0;
    c=0;
    for(int j=0; j<N; j++){
        a=j;
        b=a;
        for(int i=1000000; i>=1;){
            if(a!=a%i){
                b+=a/i;
                // a-=(a/i)*i;
                // cout<<b<<'\n';
                a=a%i;
            }
            if(b>N) break;
            if(i==1 && b==N){
                // c=N-72+j;
                c=j;
                cout<<c<<'\n';
                return 0;
            }
            i=i/10;
               
        }
        if(j==N-1){
            cout<<"0"<<'\n';
            return 0;
        }
        
    }
    return 0;
}
