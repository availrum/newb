#include<iostream>
#include<cmath>
using namespace std;
int main(){ //1058
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,kim,lim;
    cin>>N>>kim>>lim;
    int idx=1;
    while(N>idx){
        idx*=2;
    }
    int ov=idx-1;
    kim+=ov;
    lim+=ov;
    int ov_kim=kim/2;
    int ov_lim=lim/2;
    int cur_round=1;
    while(ov_kim!=ov_lim){
        ov_kim/=2;
        ov_lim/=2;
        ++cur_round;
    }
    cout<<cur_round<<'\n';
} 