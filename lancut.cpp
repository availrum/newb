#include<iostream>
using namespace std;
int main(){//1654
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int K,N,temp=0,sum=0,min,max,mid,maxl,sol;
    cin>>K>>N;
    long long int lan[K+1];
    for(long long int i=0; i<K; i++){
        cin>>lan[i];
        if(maxl<lan[i]) maxl=lan[i];
    }
    min=1, max=maxl;
    sol=0;
    while(min<=max){
        mid=(min+max)/2;
        temp=0;
        for(long long int i=0; i<K; i++){
            temp+=lan[i]/mid;
        }
        if(N <= temp){//개수이상이면
            if(mid>=sol){
                sol=mid;
                min=mid+1;
            }
            else min=mid+1;
        }
        else max=mid-1;
    }
    cout<<sol<<'\n';
}