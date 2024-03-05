#include<iostream>
using namespace std;
int main(){
    int a=0;
    string s;
    cin>>s;
    for(int i=0; i<s.size(); i++){
        if(int(s[i])<80){
            a+=(int(s[i])-2)/3-18;
        }
        else if(int(s[i])<84){
            a+=(int(s[i]))/4-12;
        }
        else if(int(s[i])<87){
            a+=(int(s[i])/3-19);
        }
        else{
            a+=10;
        }
    }
    cout<<a<<'\n';
}