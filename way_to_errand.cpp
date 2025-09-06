#include<iostream>
using namespace std;
int main(){ //5554
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N=4,sec, total_time=0;
    for(int i=0; i<N; ++i){
        cin>>sec;
        total_time+=sec;
    }
    cout<<total_time/60<<'\n';
    cout<<total_time%60<<'\n';
}