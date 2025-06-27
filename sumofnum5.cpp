#include<iostream>
using namespace std;
int main(){ //2018
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    int cnt=0;
    int lft=1, rgt=1;
    int cur_sum=lft;
    while(lft<=N){
        if(cur_sum==N){
            ++cnt;
            cur_sum-=lft;
            ++lft;
        }
        else if(cur_sum<N && rgt<N){
            ++rgt;
            cur_sum+=rgt;
        }
        else if(cur_sum>N){
            cur_sum-=lft;
            ++lft;
        }
        else break;
    }
    cout<<cnt<<'\n';
}