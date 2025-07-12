#include<iostream>
#include<algorithm>
using namespace std;
int main(){ //28353
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,K;
    cin>>N>>K;
    int cat[N];
    for(int i=0; i<N; ++i){
        cin>>cat[i];
    }
    sort(cat,cat+N);
    int lft=0, rgt=N-1, happy=0;
    while(lft<rgt){

        int sum=cat[lft]+cat[rgt];
        if(sum>K){
            --rgt;
        }
        else{
            ++happy;
            ++lft;
            --rgt;
        }
    }
    cout<<happy<<'\n';
}