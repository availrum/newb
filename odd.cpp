#include<iostream>
using namespace std;
int main(){ //2576
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, odd_sum=0, min_odd=100;
    for(int i=0; i<7; ++i){
        cin>>t;
        if(t%2==1){
            odd_sum+=t;
            min_odd=min(min_odd,t);
        }
    }
    if(min_odd!=100){
        cout<<odd_sum<<'\n';
        cout<<min_odd<<'\n';
    }
    else cout<<"-1\n";
}