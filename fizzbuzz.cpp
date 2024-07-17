#include<iostream>
using namespace std;
int main(){//28702
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int flag=0;
    for(int i=0; i<3; ++i){
        string st;
        cin>>st;
        if(flag==1) continue;
        else if(isdigit(st[0])){
            int t=stoi(st);
            flag=1;
            if(i==0){
                t+=3;
                if(t%3==0){
                    if(t%5==0) cout<<"FizzBuzz"<<'\n';
                    else cout<<"Fizz"<<'\n';
                }
                else{
                    if(t%5==0) cout<<"Buzz"<<'\n';
                    else cout<<t<<'\n';
                }
            }
            else if(i==1){
                t+=2;
                if(t%3==0){
                    if(t%5==0) cout<<"FizzBuzz"<<'\n';
                    else cout<<"Fizz"<<'\n';
                }
                else{
                    if(t%5==0) cout<<"Buzz"<<'\n';
                    else cout<<t<<'\n';
                }
            }
            else if(i==2){
                t+=1;
                if(t%3==0){
                    if(t%5==0) cout<<"FizzBuzz"<<'\n';
                    else cout<<"Fizz"<<'\n';
                }
                else{
                    if(t%5==0) cout<<"Buzz"<<'\n';
                    else cout<<t<<'\n';
                }

            }
        }
    }
}