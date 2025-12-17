#include<iostream>
using namespace std;
int main(){ //1049
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    int set_price,single_price;
    int min_set_price=6001, min_single_price=1001; 
    for(int i=0; i<M; ++i){
        cin>>set_price>>single_price;
        min_set_price=min(min_set_price,set_price);
        min_single_price=min(min_single_price,single_price);
    }
    int cost=0;
    if(min_set_price<=min_single_price*6){
        cost+=(N/6)*min_set_price;
        if((N%6)*min_single_price<min_set_price) cost+=(N%6)*min_single_price;
        else cost+=min_set_price;
    }
    else cost=N*min_single_price;
    cout<<cost<<'\n';
}