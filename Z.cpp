#include<iostream>
#include<cmath>
using namespace std;
int main(){//1074
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,numN,r,c,cnt=0;
    cin>>N>>r>>c;
    numN=pow(2,N);
    while(numN>1){
        if(r>=numN/2){//행의 절반
            if(c>=numN/2){
                cnt+=(numN/2)*(numN/2)*3; //열의 절반
                c-=numN/2;
            }
            else cnt+=(numN/2)*(numN/2)*2;
            r-=numN/2;
        }
        else{
            if(c>=numN/2){
                cnt+=(numN/2)*(numN/2);
                c-=numN/2;
            }
        }
        numN/=2;
    }
    cout<<cnt<<'\n';
}