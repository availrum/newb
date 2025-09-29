#include<iostream>
#include<ctime>
using namespace std;
int main(){ //10699
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    time_t cur_time=time(0)+3600*9;
    tm* kr_time=gmtime(&cur_time);
    char buffer[80];
    strftime(buffer,sizeof(buffer),"%Y-%m-%d",kr_time);
    // strftime(buffer,sizeof(buffer),"%Y-%m-%d %H:%M:%S",kr_time);
    cout<<buffer<<'\n';

}