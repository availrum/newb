#include<iostream>
using namespace std;
void add(string& st1, string& st2){
    int tmp=0;
    string sol="";
    for(int i=0; i<max(st1.length(), st2.length()); ++i){
        if(st1.length()>i){
            tmp+=st1[st1.length()-1-i]-'0';
        }
        if(st2.length()>i){
            tmp+=st2[st2.length()-1-i]-'0';
        }
        cout<<tmp<<'\n';
        sol+=to_string(tmp%10);
        tmp/=10;
    }
    if(tmp!=0) sol+=to_string(tmp);
    for(int i=sol.length()-1; i>=0; --i){
        cout<<sol[i];
    }
    cout<<'\n';
}
int main(){ //10757
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string st1,st2;
    cin>>st1>>st2;
    add(st1,st2);
}