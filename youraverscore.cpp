#include<iostream>
using namespace std;
int main(){
    string a,c;
    double b,sum=0,num=0;
    while(cin>>a>>b>>c){
        if(c=="A+") sum+=4.5*b;
        else if(c=="A0") sum+=4.0*b;
        else if(c=="B+") sum+=3.5*b;
        else if(c=="B0") sum+=3.0*b;
        else if(c=="C+") sum+=2.5*b;
        else if(c=="C0") sum+=2.0*b;
        else if(c=="D+") sum+=1.5*b;
        else if(c=="D0") sum+=1.0*b;
        else if(c=="F") ;
        else if(c=="P") continue;
        num+=b;
    }
    sum/=num;
    cout<<sum<<'\n';
}