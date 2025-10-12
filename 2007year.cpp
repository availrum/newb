#include<iostream>
using namespace std;
int main(){ //1924
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int day=0;
    int x,y;
    cin>>x>>y;
    for(int i=1; i<x; ++i){
        if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10) day+=3;
        else if(i==2) continue;
        else day+=2;
        day%=7; 
    }
    int remain=(y-1)%7;
    day=(day+remain)%7;
    if(day==0) cout<<"MON\n";
    else if(day==1) cout<<"TUE\n";
    else if(day==2) cout<<"WED\n";
    else if(day==3) cout<<"THU\n";
    else if(day==4) cout<<"FRI\n";
    else if(day==5) cout<<"SAT\n";
    else if(day==6) cout<<"SUN\n"; 
}