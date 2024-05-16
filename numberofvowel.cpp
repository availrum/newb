#include<iostream>
using namespace std;
int main(){//1264
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num=0;
    char st;
    while(cin>>st){
        if(st=='a' || st=='A') num++;
        if(st=='e' || st=='E') num++;
        if(st=='i' || st=='I') num++;
        if(st=='o' || st=='O') num++;
        if(st=='u' || st=='U') num++;
        if(st=='.' || st=='!' || st=='?'){
            cout<<num<<'\n';
            num=0;
            continue;
        }
        if(st=='#') break;
    }
}