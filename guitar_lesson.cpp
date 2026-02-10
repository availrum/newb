#include<iostream>
using namespace std;
int main(){ //2343
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    int lesson[N];
    for(int i=0; i<N; ++i){
        cin>>lesson[i];
    }
    int st=1, ed=1000000000, mid, minsize=1000000000;
    while(st<=ed){
        mid=(st+ed)/2;
        int idx=0, num=0;
        int blueray[M]={0,};
        while(num<N){
            if(idx>=M) break;

            blueray[idx]+=lesson[num];
            ++num;
            if(blueray[idx]>mid){
                --num;
                blueray[idx]-=lesson[num];
                ++idx;
            }
        }
        if(num!=N) st=mid+1;
        else{
            ed=mid-1;
            minsize=min(minsize,mid);
        }
    }
    cout<<minsize<<'\n';
}