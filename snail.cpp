#include<iostream>
using namespace std;
int main(){//2869
    long a,b,c;
    long time = 1;
    cin>>a>>b>>c;
    if(c==a) time=1;
    else if((c-a)%(a-b)==0){//
        time+=(c-a)/(a-b);
    }
    else if(((c-a)/(a-b)+a)>c){
        time+=(c-a)/(a-b);
    }
    else {
        time+=((c-a)/(a-b)+1);
        cout<<"oh no"<<'\n';
    }
    cout<<time<<'\n';
    return 0;
}